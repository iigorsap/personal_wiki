from fastapi import FastAPI, File, UploadFile, Form, Body
from fastapi.responses import HTMLResponse

from typing import Annotated, Union

app = FastAPI()


# File is a class that inherits directly from Form.
@app.post("/files/")
async def create_file(file: Annotated[bytes, File()]):
    return {"file_size": len(file)}


"""
UploadFile -> use spooled file to storage in memory -> object python SpooledTemporaryFile
UploadFile ATTRS:
- filename (myimage.jpg)
- content_type (image/jpeg)
- file (SpooledTemporaryFile: file-like object)

Um objeto que expõe uma API orientada a arquivos (com métodos como read() ou write())
a um recurso subjacente. Dependendo da maneira como foi criado, um objeto de 
arquivo pode mediar o acesso a um arquivo real no disco ou a outro tipo de 
dispositivo de armazenamento ou comunicação (por exemplo, entrada/saída padrão, 
buffers na memória, soquetes, pipes etc.). Os objetos de arquivo também são 
chamados de objetos semelhantes a arquivos ou fluxos.

Na verdade, há três categorias de objetos de arquivo: 
arquivos binários brutos, 
arquivos binários com buffer e arquivos de texto. 
Suas interfaces são definidas no módulo io. 
A maneira canônica de criar um objeto de arquivo é usar a função open().
"""

"""
O UploadFile tem os seguintes métodos assíncronos. Todos eles chamam os métodos 
de arquivo correspondentes abaixo (usando o SpooledTemporaryFile interno).

- write(data): Grava dados (str ou bytes) no arquivo.
- read(size): Lê o tamanho (int) de bytes/caracteres do arquivo.
- seek(offset): Vai para a posição de byte offset (int) no arquivo.
    Por exemplo, await myfile.seek(0) iria para o início do arquivo. (Tipo no C)
    Isso é especialmente útil se você executar await myfile.read() uma vez e depois 
    precisar ler o conteúdo novamente.
- close(): Fecha o arquivo.

Como todos esses métodos são métodos assíncronos, você precisa "await" eles.

O UploadFile da FastAPI herda diretamente do UploadFile da Starlette, 
mas acrescenta algumas partes necessárias para torná-lo compatível com 
o Pydantic e com as outras partes da FastAPI.

"""


@app.post("/uploadfile/")
async def create_upload_file(file: UploadFile):
    return {"filename": file.filename}


"""Optional files"""


@app.post("/files1/")
async def create_file(file: Annotated[bytes | None, File()] = None):
    if not file:
        return {"message": "No file sent"}
    else:
        return {"file_size": len(file)}


@app.post("/uploadfile1/")
async def create_upload_file(file: UploadFile | None = None):
    if not file:
        return {"message": "No upload file sent"}
    else:
        return {"filename": file.filename}


"""UploadFile with Additional Metadata"""


@app.post("/files2/")
async def create_file(file: Annotated[bytes, File(description="A file read as bytes")]):
    return {"file_size": len(file)}


@app.post("/uploadfile2/")
async def create_upload_file(
    file: Annotated[UploadFile, File(description="A file read as UploadFile")],
):
    return {"filename": file.filename}


"""Multiple File Uploads"""


@app.post("/files3/")
async def create_files(files: Annotated[list[bytes], File()]):
    return {"file_sizes": [len(file) for file in files]}


@app.post("/uploadfiles3/")
async def create_upload_files(files: list[UploadFile]):
    return {"filenames": [file.filename for file in files]}


@app.get("/")
async def main():
    content = """
        <body>
        <form action="/files/" enctype="multipart/form-data" method="post">
        <input name="files" type="file" multiple>
        <input type="submit">
        </form>
        <form action="/uploadfiles/" enctype="multipart/form-data" method="post">
        <input name="files" type="file" multiple>
        <input type="submit">
        </form>
        </body>
    """
    return HTMLResponse(content=content)


"""
Define File and Form parameters

Pode declarar vários parâmetros File e Form em uma operação de caminho, 
mas não pode declarar também os campos Body que espera receber como JSON, 
pois a solicitação terá o corpo codificado usando multipart/form-data em vez de application/json.

Isso é uma limitação do método HTTP
"""


@app.post("/files4/")
async def create_file(
    file: Annotated[bytes, File()],
    fileb: Annotated[UploadFile, File()],
    token: Annotated[str, Form()],
):
    return {
        "file_size": len(file),
        "token": token,
        "fileb_content_type": fileb.content_type,
    }
