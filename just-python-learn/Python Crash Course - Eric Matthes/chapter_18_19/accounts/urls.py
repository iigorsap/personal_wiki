"""Defines URL patterns for accounts."""
from django.urls import path, include

app_name = 'accounts'
from . import views

urlpatterns = [
    # Include default auth urls.
    path('', include('django.contrib.auth.urls')),
    # Registration page.
    path('register/', views.register, name='register'),
]