from django.db import models

# Create your models here.
class Usuario(models.Model):
    username = models.CharField(max_length=150, unique=True)  # Username com máximo de 150 caracteres e deve ser único
    password = models.CharField(max_length=128)  # Armazenar a senha com até 128 caracteres
    last_login = models.DateTimeField(null=True, blank=True)  # Campo para armazenar a data e hora do último login

    def __str__(self):
        return self.username  # Representação do objeto como string