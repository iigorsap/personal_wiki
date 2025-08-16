// import { createFileRoute } from "@tanstack/react-router";
// import { queryOptions, useSuspenseQuery } from "@tanstack/react-query";
// import { queryClient } from "../queryClient";
// import { fetchPost } from "../api";
// import { Post } from "../components/Post";

// const postQueryOptions = (postId: string) =>
//   queryOptions({
//     queryKey: ["post", postId],
//     queryFn: () => fetchPost(postId),
//   });

// export const Route = createFileRoute("/website/$postId")({
//   loader: ({ params }) =>
//     queryClient.ensureQueryData(postQueryOptions(params.id)),
//   component: () => {
//     const { id } = Route.useParams();
//     const { data: post } = useSuspenseQuery(postQueryOptions(id));
//     return <Post post={post} />;
//   },
// });

