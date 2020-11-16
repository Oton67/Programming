<?php
    include 'headerfooter.php';

    if($_SERVER['REQUEST_METHOD'] === "POST"){
        include "connect.php";

        $ime = $_POST['ime'];
        $prezime = $_POST['prezime'];
        $username = $_POST['username'];
        $password = $_POST['password'];
        $password_hash = password_hash($password, CRYPT_BLOWFISH);
        $razina = 0;
        
        $registriraniKorisnik = false;
        $sql = "SELECT korisnickoIme FROM korisnik WHERE korisnickoIme = ?";
    
        $stmt = mysqli_stmt_init($dbc);
        if(mysqli_stmt_prepare($stmt, $sql)){
            mysqli_stmt_bind_param($stmt, 's', $username);
            mysqli_stmt_execute($stmt);
            mysqli_stmt_store_result($stmt);
        }
        
        if(mysqli_stmt_num_rows($stmt) > 0){
            $msg = 'Korisničko ime već postoji!';
        }
        else{
            $sql = "INSERT INTO korisnik(ime, prezime, razina, korisnickoIme, lozinka) VALUES(?, ?, ?, ?, ?);";
        
            $stmt = mysqli_stmt_init($dbc);
            
            if(mysqli_stmt_prepare($stmt, $sql)){
                mysqli_stmt_bind_param($stmt, 'ssiss', $ime, $prezime, $razina, $username, $password_hash);
                mysqli_stmt_execute($stmt);
                $registriraniKorisnik = true;
            
            }
        }
    }
?>
<!DOCTYPE html>
<html>

<?php
    printHead("Registracija");
?>

<body>
    <?php
        printHeader();
    ?>
    <main class="container main">
        <div class="row equal">

            <article class="col-md-12 clanak">
                <h2>Registracija</h2>
                <form action="registracija.php" method="POST" class="text-center" id="registracija">
                    <div class="form-group">
                            <label for="ime">Ime</label>
                            <input type="text" class="form-control" name="ime" id="ime" aria-describedby="ime" placeholder="Ime">
                            <span id='imeErrorSpan'></span>
                    </div>

                    <div class="form-group">
                            <label for="prezime">Prezime</label>
                            <input type="text" class="form-control" name="prezime" id="prezime" aria-describedby="prezime" placeholder="Prezime">
                            <span id='prezimeErrorSpan'></span>
                    </div>

                    <div class="form-group">
                        <label for="username">Korisničko ime</label>
                        <input type="text" class="form-control" name="username" id="username" aria-describedby="Korisničko ime" placeholder="Unesite korisničko ime">
                        <span id='usernameErrorSpan'></span>
                    </div>
                    <div class="form-group">
                        <label for="password">Lozinka</label>
                        <input type="password" class="form-control" name="password" id="password" aria-describedby="password" placeholder="Unesite lozinku">
                        <span id='passwordErrorSpan'></span>
                    </div>

                    <div class="form-group">
                        <label for="lozinkaponovi">Lozinka ponovno</label>
                        <input type="password" class="form-control" name="lozinkaponovi" id="passwordponovi" aria-describedby="lozinkaponovi" placeholder="Unesite lozinku ponovno">
                        <span id='passwordponoviErrorSpan'></span>
                    </div>

                    <div class="form-check">
                        <button type="button" class="btn btn-primary" id="registriraj">Registriraj me</button>
                    </div>

                    
                    <div class="form-check">
                        <?php
                            if(isset($registracija)){
                                if($registracija == true){
                                    echo "<p>Uspješna registracija!</p>";
                                }
                            }

                            if(isset($msg)){
                                echo "<p>$msg</p>";
                            }
                            
                        ?>
                    </div>

                </form>


            </article>
        </div>


    </main>


    <script>
        document.getElementById('registriraj').onclick = function(event){

            var ime = document.getElementById('ime');
            var prezime = document.getElementById('prezime');
            var username = document.getElementById('username');
            var password = document.getElementById('password');
            var passwordponovi = document.getElementById('passwordponovi');

            var ok = true;

            if(ime.value.length == 0){
                ok = false;
                
                ime.style.border = "1px solid red";

                var imeErrorSpan = document.getElementById("imeErrorSpan");
                imeErrorSpan.style.color = "red";
                imeErrorSpan.innerHTML = "Unesite ime!";
            }

            if(prezime.value.length == 0){
                ok = false;
                
                prezime.style.border = "1px solid red";

                var prezimeErrorSpan = document.getElementById("prezimeErrorSpan");
                prezimeErrorSpan.style.color = "red";
                prezimeErrorSpan.innerHTML = "Unesite prezime!";
            }

            if(username.value.length == 0){
                ok = false;
                
                username.style.border = "1px solid red";

                var usernameErrorSpan = document.getElementById("usernameErrorSpan");
                usernameErrorSpan.style.color = "red";
                usernameErrorSpan.innerHTML = "Unesite korisničko ime!";
            }

            if(password.value.length < 6 || password.value.length > 20){
                ok = false;
                
                password.style.border = "1px solid red";

                var passwordErrorSpan = document.getElementById("passwordErrorSpan");
                passwordErrorSpan.style.color = "red";
                passwordErrorSpan.innerHTML = "Lozinka mora biti između 6 i 20 znakova!";
            }

            if(password.value != passwordponovi.value || passwordponovi.value.length == 0){
                ok = false;

                passwordponovi.style.border = "1px solid red";

                var passwordponoviErrorSpan = document.getElementById("passwordponoviErrorSpan");
                passwordponoviErrorSpan.style.color = "red";
                passwordponoviErrorSpan.innerHTML = "Lozinke moraju biti iste!";
            }

            if(ok != true){

                event.preventDefault();
                return false;

            }


            document.forms['registracija'].submit();
            return true;
        }


    </script>



    <?php
        printFooter();
    ?>




</body>

</html>