import requests
from bs4 import BeautifulSoup

#Aim is to print a list of all the titles from nzherald.co.nz

#requesting info from the nzherald
r = requests.get('https://nzherald.co.nz')
#getting html
web_page = r.text
# Passing to BeautifulSoup
workpls = BeautifulSoup(web_page)

#Matching all the titles, which were all h3 at this website
titles = workpls.find_all('h3')

#Saving to text file
filee = open('C:/Users/Matt/Downloads/Life man/Crypto/datasci/Python programs/Titles.txt', 'w')

#Writing to text file
for i in range(0,len(titles)):
    filee.write(titles[i].get_text() +'\n')

filee.close()
print('File created!')
