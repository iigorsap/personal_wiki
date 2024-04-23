from django.db import models
from django.contrib.auth.models import User

class Topic(models.Model):
    """A topic the user is learning about."""
    text = models.CharField(max_length=200)
    date_added = models.DateTimeField(auto_now_add=True)
    owner = models.ForeignKey(User, on_delete=models.CASCADE)
    
    def __str__(self):
        """Return a string representation of the model."""
        return self.text

"""
Para que um usuário registre o que tem aprendido sobre xadrez e escalada, 
precisamos definir um modelo para os tipos de entradas que os usuários podem 
fazer em seus registros de aprendizagem. Cada entrada precisa ser associada a 
um tópico específico.

Essa relação é chamada de relação muitos-para-um, o que significa que muitas 
entradas podem ser associadas a um tópico.
"""

class Entry(models.Model):
    """Something specific learned about a topic."""
    topic = models.ForeignKey(Topic, on_delete=models.CASCADE)
    text = models.TextField()
    date_added = models.DateTimeField(auto_now_add=True)

    class Meta:
        verbose_name_plural = 'entries'

    def __str__(self):
        """Return a simples string representing the entry"""
        return f"{self.text[:50]}..."