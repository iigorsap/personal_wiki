import { createFileRoute } from "@tanstack/react-router";

export const Route = createFileRoute("/website/$websiteId")({
    component: RouteComponent,
    loader: async ({ params }) => {
        // throw new Error("Invalid Component");
        await new Promise((resolve) => setTimeout(resolve, 1000));
        return {
            websiteId: params.websiteId,
        };
    },
    pendingComponent: () => <div>Loading...</div>,
    errorComponent: () => <div>Error Component</div>
});

function RouteComponent() {
    const { websiteId } = Route.useLoaderData();

    return <div>Hello {websiteId}!</div>;
}
