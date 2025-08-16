import { createFileRoute } from "@tanstack/react-router";
import { apiClient } from "../../../../src/services/config";

export const Route = createFileRoute("/users/$userId")({
    loader: ({ params }) => apiClient.get(`users/${params.userId}`).then(r => r.data),
    component: UserComponent,
});

function UserComponent() {
    const { userId } = Route.useParams();
    const data = Route.useLoaderData(); // aqui você acessa os dados da API
    return  <div>
        <h1>Hello {data.email}</h1>
        <pre>{JSON.stringify(data, null, 2)}</pre>
    </div>
}
