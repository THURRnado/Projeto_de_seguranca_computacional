document.querySelector('.toggle-password').addEventListener('click', function (e) {
    let passwordInput = document.getElementById('password');
    let icon = e.target;
    // Toggle o tipo entre 'password' e 'text'
    if (passwordInput.type === "password") {
        passwordInput.type = "text";
        icon.classList.remove('fa-eye');
        icon.classList.add('fa-eye-slash');
    } else {
        passwordInput.type = "password";
        icon.classList.remove('fa-eye-slash');
        icon.classList.add('fa-eye');
    }
});