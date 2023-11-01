from django.urls import path # power our URLpattern
from .views import homePageView

urlpatterns = [
    path('', homePageView, name='home')

    # path([1]): a python regular expression for the empty string ''
    # path([2]): a reference to the view called homePageView
    # path([3]): an optional named URL pattern called 'home'

    
    
]
