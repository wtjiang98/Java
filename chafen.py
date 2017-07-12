

<<<<<<< HEAD
=======
import requests

def changeinco(x):
    cookies = requests.utils.cookiejar_from_dict(x, cookiejar=None, overwrite=True)
    return cookies

mycoo = 'JSESSIONID=ZjCHsSvfQ8tnYgxZ54cp3M841ps06kcT7phFvRnJBJCVh1rYmTnQ!1465092685'
data = {
    'WebUserNO': "2015201108"
    'Password': 'jwt19980331'
    'Agnomen': '6728'
    'submit.x' :"26"
   'submit.y'	:"8"
    'applicant'	:"ACTIONQUERYSTUDENTSCORE"
}
url = 'http://jw.hrbeu.edu.cn/ACTIONLOGON.APPPROCESS'

s = requests.session()
cur = s.get(url)

print(cur, cur.text)
>>>>>>> 55ee2e4b0fa3b5f514586363981c79256547551c
