from django.views.generic.base import TemplateView
from django.shortcuts import render, redirect
from django.contrib.auth import authenticate, login
from django.contrib import messages
from .models import Usuario
from django.contrib.auth.hashers import check_password

# Create your views here.
class IndexView(TemplateView):
    template_name = "login.html"
    
class InicioView(TemplateView):
    template_name = "inicio.html"
    
class CadastroView(TemplateView):
    template_name = "cadastro.html"


def autenticarUsuario(request):
    if request.method == 'POST':
        username = request.POST.get('username')
        password = request.POST.get('password')

        try:
            user = Usuario.objects.get(username=username)
            if user.password == password:
                login(request, user)  # Se a senha estiver correta, faz o login
                messages.success(request, 'Login realizado com sucesso!')
                return redirect('inicio')  # Redirecionar para a página desejada
            else:
                messages.error(request, 'Nome de usuário ou senha incorretos.')
        except Usuario.DoesNotExist:
            messages.error(request, 'Nome de usuário ou senha incorretos.')

    return render(request, 'login.html')  # Renderiza o template de login novamente



def registrarUsuario(request):
    if request.method == 'POST':
        username = request.POST.get('username')
        password = request.POST.get('password')
        confirm_password = request.POST.get('confirm_password')

        # Verifica se as senhas coincidem
        if password != confirm_password:
            messages.error(request, 'As senhas não coincidem.')
            return render(request, 'cadastro.html')  # Renderiza o template de cadastro novamente

        # Cria o novo usuário
        try:
            usuario = Usuario(username=username, password=password)  # Instancia o usuário
            usuario.save()  # O método save já cuida de hashear a senha
            messages.success(request, 'Usuário cadastrado com sucesso! Faça login.')
            return redirect('fazer_login')  # Redireciona para a página de login
        except Exception as e:
            messages.error(request, 'Erro ao cadastrar o usuário. Tente novamente.')
            return render(request, 'cadastro.html')  # Renderiza o template de cadastro novamente

    return render(request, 'cadastro.html')  # Renderiza o template de cadastro se não for um POST
