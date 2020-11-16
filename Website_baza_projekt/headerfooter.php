<?php
session_start();


function printHead($naslov){
    echo
    "
    <head>
    <meta charset='utf-8'>
    <meta http-equiv='X-UA-Compatible' content='IE=edge'>
    <title>$naslov</title>
    <meta name='viewport' content='width=device-width, initial-scale=1'>
    <!-- Bootstrap 4 -->
    <link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css'>
    <script src='https://ajax.googleapis.com/ajax/libs/jquery/3.4.0/jquery.min.js'></script>
    <script src='https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js'></script>
    <script src='https://maxcdn.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js'></script>
    <script src='js/script.js'></script>
    <link rel='stylesheet' href='css/style.css'>
    </head>
    ";

}

function printHeader(){
    echo 
    "<header class='header container navigation-white'>
    <div class='row justify-content-center align-items-center'>
        <a href='index.php' class='nounderline'><h1 class='naslov'>El Confidencial</h1></a>
    </div>
    <div class='undertitle'>EL DIARIO DE LOS LECTORES INFLUYENTES</div><br>

    <div class='row justify-content-center align-items-center'>
    
    <nav class='row navbar navbar-expand-lg navbar-dark navigation-white'>
    <div class='row'>
        <a class='nav-link' href='index.php'>HOME</a>
        <button class='navbar-toggler' type='button' data-toggle='collapse' data-target='#navbarSupportedContent'
            aria-controls='navbarSupportedContent' aria-expanded='false' aria-label='Toggle navigation'>
            <span class='navbar-toggler-icon'></span>
        </button>
    
        <div class='collapse navbar-collapse' id='navbarSupportedContent'>
            <ul class='navbar-nav mr-auto'>
                <li class='nav-item'>
                    <a class='nav-link' href='kategorija.php?id=1'>EUROPA</a>
                </li>
                <li class='nav-item'>
                    <a class='nav-link' href='kategorija.php?id=2'>TEKNAUTAS</a>
                </li>
                <li class='nav-item'>
                    <a class='nav-link' href='administracija.php'>ADMINISTRACIJA</a>
                </li>
                ";

                if(isset($_SESSION['username']) == false){
                    echo "<li class='nav-item'>
                    <a class='nav-link' href='prijava.php'>LOGIN</a>
                </li>

                <li class='nav-item'>
                    <a class='nav-link' href='registracija.php'>REGISTER</a>
                </li>";
                }


                           
                if(isset($_SESSION['username']) && isset($_SESSION['level'])){
                    echo
                    "<li class='nav-item'>
                    <a class='nav-link' href='logout.php'>LOGOUT</a>
                    </li>";
                    }
                
                echo "
            </ul>
    
        </div>
    </nav>
    </div>
    <hr class='hr1'>
    </header>";
}

function printFooter(){
    echo
    "<footer class='container footer'>
    <div class='row justify-content-center align-items-center'>

    <p class='footer'>&copy;TITANIA COMPANIA EDITORIAL, S.L.2019. Espana.&nbsp;
    <a href='#home'>Todos los derechos reservados</a>&nbsp;
    <a href='#home'>Condiciones</a>&nbsp;
    <a href='#home'>Politica de Privacidad</a>&nbsp;
    <a href='#home'>Policia de Cookies</a>&nbsp;
    <a href='#home'>Transparencia</a>&nbsp;
    <a href='#home'>Auditado por ComScore</a>
    </p>

    </div>
    </footer>";
}




?>