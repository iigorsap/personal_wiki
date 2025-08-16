import { createFileRoute, Link } from "@tanstack/react-router";

export const Route = createFileRoute("/website/")({
    component: RouteComponent,
    validateSearch: (search) => {
        return {
            q: (search.q as string) || "",
        };
    },
    loaderDeps: ({ search: { q } }) => ({ q }),
    loader: async ({ deps }) => {
        const { q } = deps;
        const eventInformation = ["info1", "info2", "info3"];
        return {
            eventInformation: eventInformation.filter((e) => e === q),
        };
    },
});

function RouteComponent() {
    const { eventInformation } = Route.useLoaderData();
    const { q } = Route.useSearch();

    return (
        <div>
            {eventInformation.map((e) => (
                <div key={e}>
                    <Link
                        to="/website/$websiteId"
                        params={{
                            websiteId: e,
                        }}>
                        {e}
                    </Link>
                </div>
            ))}
        </div>
    );
}
