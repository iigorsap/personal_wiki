import { useState } from 'react'
import { useForm, useFieldArray, Controller } from 'react-hook-form'
import './App.css'
import * as Yup from "yup";
import { yupResolver } from '@hookform/resolvers/yup'

// Estrutura, tipo, campos do formulario e validação
const createUserFormSchema = Yup.object({
    name: Yup.string()
        .lowercase(),
    email: Yup.string()
        .email("Formato de e-mail inválido")
        .required("E-mail obrigatório"),
    description: Yup.string(),
    cost_centers: Yup.number(),
    groupUser: Yup.array().of(
        Yup.object({
            name: Yup.string()
                .required()
        })),
})

// Caso queira fazer um tipo de campo que vou adicionar ou remover quantidades de 
// inputs usamos useFieldArray, exemplo de uso seria um campo de adicionar vários usuários
// em um grupo específico, conforme fosse adicionando, poderia criar novas entradas, com novos dados.




const App = () => {
    const [output, setOutput] = useState('')

    // Register: Usado para falar com o hook-form qual será os campos do nosso form,
    //      cadastrando eles em cada input usando o spreed operator.
    // 
    // Para o formulário entender as validações é preciso passar um arquivo (funcao) de configuração para o useForm.
    // 
    const { register, handleSubmit, formState: { errors }, control, } = useForm({
        // Aqui você passa a validação mas ainda não aparece os erros, para isso é necessario utilizar o formState que o useForm retorna para usar
        resolver: yupResolver(createUserFormSchema)
    })

    // Caso queira fazer um tipo de campo que vou adicionar ou remover quantidades de 
    // inputs usamos useFieldArray, exemplo de uso seria um campo de adicionar vários usuários
    // em um grupo específico, conforme fosse adicionando, poderia criar novas entradas, com novos dados.
    // UseFieldRetorna algumas propriedades dentre elas:
    //      fields: Os campos que foram declarados na schema
    //      append: Adicionar um novo elemento
    //      remove: Remover um novo elemento

    const { fields, append, remove } = useFieldArray({
        control, // associa o campo ao nosso formulário, o control é uma propriedade retornada pelo useForm
        name: "groupUser" // nome do campo, aqui estamos criando um novo campo do Form, ele precisa estar definido no Schema.
    })

    console.log(errors)
    const createUser = (data) => {
        // Para evitar "undefined", remove o campo se não houver grupos
        if (data.groupUser.length === 0) {
            delete data.groupUser
        }
        setOutput(JSON.stringify(data, null, 4))
        console.log(output)
    };


    // High Order Function:
    //      onSubmit={handleSubmit(createUser)} 
    // Uma funcao para outra funcao
    return (

        // Usando Controller : Auxiliando na integração de um componente personalizado ao react-hook-form
        <main>
            <form onSubmit={handleSubmit(createUser)} action="">
                <div className='container'>
                    <Controller
                        name='name'
                        control={control}
                        defaultValue='default'
                        rules={{
                            required: true,
                            min: 3,
                            pattern: {
                                value: '/[A-Za-z]/',
                                message: "O nome de usuário deve conter apenas letras e números"
                            }
                        }}
                        render={({ field, fieldState: { error } })}

                    />
                </div>
            </form>
            <pre>{output}</pre>
        </main>

        /*
        // Sem Controller
        <main>
            <form onSubmit={handleSubmit(createUser)} action="">
                <div className='container'>
                    <label htmlFor="">Name</label>
                    <input
                        type="text"
                        // name='name' usando o register o nome já é atribuido pelo
                        className='input-name'
                        {...register('name')} />
                    {errors.name && <span>{errors.name.message}</span>}
                    <label htmlFor="">E-mail</label>
                    <input
                        type="email"
                        // name='email' usando o register o nome já é atribuido pelo
                        className='input-email'
                        {...register('email')} />
                    {errors.email && <span>{errors.email.message}</span>}

                    <label htmlFor="">Description</label>
                    <input
                        type="text"
                        // name='description' usando o register o nome já é atribuido pelo
                        className='input-description'
                        {...register('description')} />
                    {errors.description && <span>{errors.description.message}</span>}

                    <label htmlFor="input-cost-centers">Cost Centers</label>
                    <input
                        type="number"
                        // name='cost_centers' usando o register o nome já é atribuido pelo
                        className='input-cost-centers'
                        {...register('cost_centers')} />
                    {errors.cost_centers && <span>{errors.cost_centers.message}</span>}

                    <button onClick={() => {
                        append({ name: "" })
                    }}>Adicionar novo grupo ao usuario</button>

                    {fields.map((field, index) => (
                        <div className='group-user' key={index}>
                            <label htmlFor=""> Grupo </label>
                            <input
                                {...register(`groupUser.${index}.name`)}
                                placeholder='insira o nome do grupo'
                            />

                            <button onClick={() => {
                                remove(index)
                            }}>remover user</button>
                            {errors.groupUser?.[index]?.name && (
                                <span>{errors.groupUser[index].name.message}</span>
                            )}
                        </div>
                    ))}
                </div>
                <button type="submit">Create New User</button>
            </form>
            <pre>{output}</pre>
        </main>
        */
    )
}



export default App

// const dataApprover = {
//   "name": "O VASCO VAI CAIR",
//   "description": "ou o gremio",
//   "cost_centers": [
//       {
//           "id": 10
//       },
//   ],
//   "users": [
//       {
//           "id": 19
//       },
//       {
//           "id": 20
//       },
//   ]
// }
