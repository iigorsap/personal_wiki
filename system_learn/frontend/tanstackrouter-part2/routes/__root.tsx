// Arquivo que define a rota raiz (root route) da aplicacao
// CreateRootRoute: usada para criar rota principal da aplicacao
// Link: é como a tag <a>, mas melhor, ela funciona igual o link do next, que não recarrega a página inteira quando muda de url
// Outlet: Espaco reservado onde o conteudo da página atual vai aparecer.
// TanStackRouterDevtools: util para Debug

import { createRootRoute, Link, Outlet } from "@tanstack/react-router";
import { TanStackRouterDevtools } from "@tanstack/react-router-devtools";

export const Route = createRootRoute({
    /* cria a rota principal e diz que quando qualquer página for aberta,
    o que tiver dentro do component, servirá como layout será renderizado
    independente da pagina */

    
    component: () => (  
        <>
            <div className="p-2 flex gap-2">
                <Link to='/' > home </Link>
                <Link to='/users'> users </Link>
                <Link to="/users/$userId" params={{ userId: '87d1b5a2-36c6-4c8c-b8ca-2e23d9a1b2b1' }}>
                    Ir para usuário 1
                </Link>
                <Link to="a"> aaaaa </Link>
                <Link to="b"> bbbbb </Link>
            </div>
            <hr />
            <Outlet />
            {/* 
                Outlet é um ('lugar mágico') que o Tanstack Router coloca o conteudo da página atual.
                Exemplo: 
                se está em "/":
                    - ele coloca a página inicial aqui
                se está em "/about":
                    - ele coloca a página About  
            */}
            <TanStackRouterDevtools />
            {/* Painel que ajuda a ver se a rota ta ativa, qual loader foi chamado,, se navegacao ta funcionando e etc. */}
        </>
    ),
    notFoundComponent: () => <div>404 Not Found</div>,
});