// routes/users.tsx
import { createFileRoute, createRouteMask } from "@tanstack/react-router";
import { queryClient, apiClient } from "../../../../src/services/config";
import { useQuery } from "@tanstack/react-query";



export const Route = createFileRoute("/users/")({
    // Carrega os dados ANTES da renderização, mas usando o cache do React Query
    codeSplitGroupings: [["loader", "component"]],
    beforeLoad: () => ({
        fetchUsers: () =>
            queryClient.ensureQueryData({
                queryKey: ["users"],
                queryFn: () => apiClient.get("/users").then((r) => r.data),
            }),
    }),
    loader: async ({ context: { fetchUsers } }) => {
        const users = await fetchUsers();
        return users;
    },
    component: UsersComponent,
});

type User = {
    id: number;
    name: string;
    email: string;
};

function UsersComponent() {
    const { data, isLoading, isError } = useQuery<User[]>({
        // Reutiliza o cache sem repetir queryFn, já que foi garantido com ensureQueryData
        queryKey: ["users"],
        staleTime: 1000 * 60 * 5,
    });

    if (isLoading) return <p>Carregando usuários...</p>;
    if (isError) return <p>Erro ao carregar usuários</p>;

    return (
        <div>
            <h2>Lista de Usuários</h2>
            <ul>
                {data?.map((user) => (
                    <li key={user.id}>{user.email}</li>
                ))}
            </ul>
        </div>
    );
}


// using context

// 1. create context

/* // routerContext.ts
import { createRouter, createRouterContext } from '@tanstack/react-router'
import { queryClient } from './services/config' // seu queryClient
import { RouteTree } from './routeTree.gen' // gerado pelo TanStack Router

export const { RouterProvider, useRouter, createRootRouteWithContext } = createRouterContext<{
  queryClient: typeof queryClient
}>()

export const router = createRouter({
  routeTree: RouteTree,
  context: {
    queryClient,
  },
})
 */

// 2. continua usando o RouterProvider Normalmente, mas agora com o contexto.
/* import React from 'react'
import ReactDOM from 'react-dom/client'
import { RouterProvider } from './routerContext'
import { router } from './routerContext'
import { QueryClientProvider } from '@tanstack/react-query'
import { queryClient } from './services/config'

ReactDOM.createRoot(document.getElementById('root')!).render(
  <React.StrictMode>
    <QueryClientProvider client={queryClient}>
      <RouterProvider router={router} />
    </QueryClientProvider>
  </React.StrictMode>,
)
 */


// 3. Cria a rota com contexto
/* // routes/_root.tsx
import { Outlet } from '@tanstack/react-router'
import { createRootRouteWithContext } from '../routerContext'

export const Route = createRootRouteWithContext()({
  component: () => <Outlet />,
}) */


// 4. Apartir daqui usa a rota com contexto sempre com o queryClient, sem precisar ficar passando para todas as rotas, sem necessidade de usar beforeLoad
// routes/users.tsx
/* import { createFileRoute, useLoaderData } from "@tanstack/react-router"
import { apiClient } from "../services/config"

export const Route = createFileRoute("/users/")({
  loader: async ({ context }) => {
    const users = await context.queryClient.ensureQueryData({
      queryKey: ["users"],
      queryFn: () => apiClient.get("/users").then((r) => r.data),
    })
    return users
  },
  component: UsersComponent,
})

function UsersComponent() {
  const { data } = useLoaderData({ route: Route })

  return (
    <div>
      <h2>Usuários</h2>
      <ul>
        {data?.map((user) => (
          <li key={user.id}>{user.email}</li>
        ))}
      </ul>
    </div>
  )
} */