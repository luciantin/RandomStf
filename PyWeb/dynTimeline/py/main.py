from flask import Flask, render_template 


print('gello')

app = Flask(__name__, template_folder = '../html/templates')


@app.route('/')
def index():
    return render_template('index.html',ime = 'tin')




if __name__ == '__main__' :
    app.run(debug=True)
