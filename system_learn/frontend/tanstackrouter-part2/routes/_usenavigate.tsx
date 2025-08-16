/* function Component() {
  const navigate = useNavigate({ from: '/posts/$postId' })

  const handleSubmit = async (e: FrameworkFormEvent) => {
    e.preventDefault()

    const response = await fetch('/posts', {
      method: 'POST',
      body: JSON.stringify({ title: 'My First Post' }),
    })

    const { id: postId } = await response.json()

    if (response.ok) {
      navigate({ to: '/posts/$postId', params: { postId } })
    }
  }
} */