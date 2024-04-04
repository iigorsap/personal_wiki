from django.shortcuts import render
from django.views.generic import CreateView
from django.urls import reverse_lazy

from .forms import CustomUserCreationFrom

# Create your views here.

class SignUpView(CreateView):
    form_class = CustomUserCreationFrom
    template_name = "registration/signup.html"
    success_url = reverse_lazy('login')
