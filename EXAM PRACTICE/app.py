from flask import Flask, jsonify, request
from flask_jwt_extended import JWTManager, jwt_required, create_access_token, get_jwt_identity

app = Flask(__name__)

# Set up the Flask app with JWTManager
app.config['JWT_SECRET_KEY'] = 'super-secret'
jwt = JWTManager(app)

# Mock user data
users = [
    {'id': 1, 'email': 'user1@example.com', 'password': 'password1'},
    {'id': 2, 'email': 'user2@example.com', 'password': 'password2'}
]

# Login route
@app.route('/login', methods=['POST'])
def login():
    email = request.json.get('email', None)
    password = request.json.get('password', None)

    # Validate the user's email and password
    user = next((user for user in users if user['email'] == email and user['password'] == password), None)
    if not user:
        return jsonify({'message': 'Invalid credentials'}), 401

    # If the user is valid, generate an access token and return it
    access_token = create_access_token(identity=user['id'])
    return jsonify({'access_token': access_token}), 200

# Protected route
@app.route('/protected')
@jwt_required
def protected():
    # Get the user ID from the JWT
    user_id = get_jwt_identity()

    # Use the user ID to get the user data
    user = next((user for user in users if user['id'] == user_id), None)
    if not user:
        return jsonify({'message': 'User not found'}), 404

    # Return the protected data
    return jsonify({'message': f'Hello, {user["email"]}! You are authorized to access this resource.'}), 200

if __name__ == '__main__':
    app.run(debug=True)
