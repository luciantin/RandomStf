from flask import render_template
from app import app


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
        }
    ]
    return render_template('index.html', title='Home', user=user, posts=posts)
