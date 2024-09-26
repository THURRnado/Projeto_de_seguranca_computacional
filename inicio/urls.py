from django.urls import path
from .views import IndexView, InicioView, CadastroView, autenticarUsuario, registrarUsuario

urlpatterns = [
    path('', IndexView.as_view(), name='login'),
    path('inicio', InicioView.as_view(), name='inicio'),
    path('cadastro', CadastroView.as_view(), name='cadastro'),
    path('fazer_login', autenticarUsuario, name='fazer_login'),
    path('registrar_usuario', registrarUsuario, name='registrar_usuario')
    # Outros padrões de URL
]
