from django.db import models

# Create your models here.


class Post(models.Model):
    title = models.CharField(max_length=200)
    author = models.ForeignKey(  # Como serão os usuários que vão publicar os posts temos então a autenticação de cada 1.
        'auth.user',
        on_delete=models.CASCADE,
    )
    body = models.TextField()

    def __str__(self):
        return self.title
