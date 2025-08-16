# AWS
- Criei a conta (iigorsap) usando igorsantiago.aws@gmail.com
- Criei um AIM que atribuiu o meu usuário como management account.
- Após isso acessei o IAM Identity Center, pois eu precisava de um usuário com previlégio de administrador, não conseguia fazer isso com o usuário da conta.
- Criei um user chamado Igor.paixao usando o mesmo email do management account igorsantiago.aws@gmail.com, e mandei um email de cadastro de senha para essa conta.
- Após isso criei um grupo chamado admin-users
- Selecionei o checkbox na conta management, cliquei em AWS Accounts em Assign users or groups, adicionei o usuário no grupo de admin.
- Posteriormente fui em permission set, criei a AdmnistratorAccess com acesso de administrador.
- Depois fui em Assing users or groups novamente e atribui o conjunto de permissões de administrador para o grupo admin-users.
- A Partir dai tinha permissão de admin com o igor.paixao, e fui no email para fazer o login, fui deslogado da iigorsap.
- A partir dai consegui logar com o Igor.paixao e consegui criar o bucket.
- Bucket criado, adicionei as variáveis da minha conta admin no meu .zshrc, criei uma funçao mfa() para autenticar a sessão, e conseguir listar o bucket usando o python e subir uma imagem pro s3.

---
#### Fontes
- https://docs.aws.amazon.com/AmazonS3/latest/userguide/Welcome.html
- https://docs.aws.amazon.com/AmazonS3/latest/userguide/GetStartedWithS3.html#getting-started-next-steps
