from django.contrib import admin
from .models import Usuario

# Register your models here.
@admin.register(Usuario)
class UsuarioAdmin(admin.ModelAdmin):
    list_display = ('id', 'username', 'password')  # Campos a serem exibidos na lista
    search_fields = ('username',)  # Campo de pesquisa
    list_filter = ('username',)  # Filtros na lateral