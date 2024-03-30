from django.contrib.auth.models import AbstractUser
from django.db import models


"""

AbstractBaseUser vs AbstractUser
O AbstractBaseUser requer um nível muito fino de controle e personalização. 
Basicamente, reescrevemos o Django. Isso pode ser útil, mas se quisermos apenas 
um modelo de usuário personalizado que possa ser atualizado com campos adicionais, 
a melhor opção é AbstractUser, que subclasses AbstractBaseUser. 
Em outras palavras, escrevemos muito menos código e temos menos oportunidades de bagunçar as coisas. 
Essa é a melhor escolha, a menos que você realmente saiba o que está fazendo com o Django.
"""
class CustomUser(AbstractUser):
    age = models.PositiveIntegerField(null=True, blank=True)

