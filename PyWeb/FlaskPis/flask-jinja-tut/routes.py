"""Route declaration."""
from flask import current_app as app
from flask import render_template


@app.route('/')
def home():
    """Landing page."""
    return render_template('home.html',
                           title="Jinja Demo Site",
                           description="Smarter page templates \
                                with Flask & Jinja.")
