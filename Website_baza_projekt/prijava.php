<?php
    include 'headerfooter.php';

    if($_SERVER['REQUEST_METHOD'] === "POST"){
        include 'connect.php';

        $usernameForma = $_POST['username'];
        $passwordForma = $_POST['password'];

        $sql = "SELECT korisnickoIme, lozinka, razina FROM korisnik WHERE korisnickoIme = ?";

        $stmt = mysqli_stmt_init($dbc);
        if(mysqli_stmt_prepare($stmt,$sql)){
            mysqli_stmt_bind_param($stmt, 's', $usernameForma);
            mysqli_stmt_execute($stmt);
            mysqli_stmt_store_result($stmt);
        }

        mysqli_stmt_bind_result($stmt, $username, $password, $level);
        mysqli_stmt_fetch($stmt);

        if(password_verify($passwordForma, $password) && mysqli_stmt_num_rows($stmt) > 0){
            $login = true;
            
            $_SESSION['username'] = $username;
            $_SESSION['level'] = $level;
        }



        mysqli_close($dbc);

    }

?>
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Login</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- Bootstrap 4 -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.0/jquery.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js"></script>
    <link rel="stylesheet" href="css/style.css">
</head>

<body>
    <?php
        printHeader();
    ?>
    <main class="container main">
        <div class="row equal">

            <article class="col-md-12 clanak">
                <h2>Prijava</h2>
                <form action="prijava.php" method="POST" class="text-center">
                    <div class="form-group">
                        <label for="korisnickoime">Korisničko ime</label>
                        <input type="text" class="form-control" name="username" id="korisnickoime" aria-describedby="Korisničko ime" placeholder="Unesite korisničko ime">
                    </div>
                    <div class="form-group">
                        <label for="lozinka">Lozinka</label>
                        <input type="password" class="form-control" name="password" id="lozinka" aria-describedby="Loznka" placeholder="Unesite lozinku">
                    </div>

                    <div class="form-check">
                        <button type="submit" class="btn btn-primary ">Prijava</button>
                    </div>

                </form>

            
            <?php
                if(isset($_SESSION['username'])){

                    echo "<p>Uspješna prijava!</p>";
                }

            ?>

            </article>
        </div>


    </main>



    <?php
        printFooter();

    ?>




</body>

</html>