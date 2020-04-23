from flask import Flask
from flask import render_template
# from app import app

app = Flask(__name__)

# from app import routes

@app.route('/')
@app.route('/index')
def index():
    user = {'mjera': 'Corono'}
    posts = [
        {
            'zastita': {'mjera': '1.'},
            'body': 'redovno pranje ruku sapunom i toplom vodom ili dezinfekcija alkoholom'
        },
        {
            'zastita': {'mjera': '2.'},
            'body': 'kod kihanja i kašnjanja potrebno je usta prekriti maramicom ili savijenim laktom'
        },
        {
            'zastita': {'mjera': '3.'},
            'body': 'rvsdfertjh jey5tjeyja alkoholom alkoholom alkoholom'
        },
    ]
    return render_template('index.html', title='Home', user=user, posts=posts,debug=True,use_reloader=True)

if __name__ == '__main__': 
    app.run() 