<?php
    include 'connect.php';
    include 'headerfooter.php';

    if(isset($_POST['idKorisnik'])){
        $idPost = $_POST['idKorisnik'];

        $sql = "SELECT ime, prezime, razina FROM korisnik WHERE id = ?";

        $stmt = mysqli_stmt_init($dbc);

        if(mysqli_stmt_prepare($stmt, $sql)){

            mysqli_stmt_bind_param($stmt, "i", $idPost);
            mysqli_stmt_execute($stmt);

            mysqli_stmt_store_result($stmt);


        }

        mysqli_stmt_bind_result($stmt, $ime, $prezime, $razina);
        mysqli_stmt_fetch($stmt);





    
    }



  

?>
<!DOCTYPE html>
<html>


<?php
    printHead("Uredjivanje korisnika");
?>


<body>

    <main class="container main">

        <div class="row equal">
            <article class="col-md-12 clanak">
                <form id="unos" method="POST" action="php/urediKorisnika.php" enctype="multipart/form-data">

                    <h2>Promjena postojećeg korisnika!</h2>
                    <div class="form-group">
                        <label for="ime">Ime</label>
                        <input type="text" class="form-control" name="ime" id="ime" value="<?php echo $ime; ?>"
                            aria-describedby="Unesite ime" placeholder="Unesite ime">
                        <span id='imeErrorUnos'></span>
                    </div>

                    <div class="form-group">
                        <label for="prezime">Prezime</label>
                        <input type="text" class="form-control" name="prezime" id="prezime" value="<?php echo $prezime; ?>"
                            aria-describedby="Unesite prezime" placeholder="Unesite prezime">
                        <span id='prezimeErrorUnos'></span>
                    </div>

                    <div class="form-check razmak">
                        <input class="form-check-input" type="checkbox" name="razina" value="" id="razinaCheck" <?php if($razina == 1) echo "checked"; ?>> 
                        <label class="form-check-label" for="razinaCheck">
                            Admin?
                        </label>
                    </div>


                    <input type="number" hidden value="<?php echo $idPost; ?>" name="id">

                    <div class="form-group">
                        <button type="button" class="btn btn-primary" id="unosPrihvati">Prihvati</button>
                    </div>
                </form>
            </article>
        </div>


    </main>


    <script>
        document.getElementById('unosPrihvati').onclick = function (event) {

            var ime = document.getElementById('ime');
            var prezime = document.getElementById('prezime');
           
            var ok = true;

            if(ime.value == "" || ime.value.length == 0){
                ok = false;

                ime.style.border = "1px solid red";

                var imeErrorUnos = document.getElementById('imeErrorUnos');
                imeErrorUnos.style.color = "red";
                imeErrorUnos.innerHTML = "Unesite ime!";
            }

            if(prezime.value == "" || prezime.value.length == 0){
                ok = false;

                prezime.style.border = "1px solid red";

                var prezimeErrorUnos = document.getElementById('prezimeErrorUnos');
                prezimeErrorUnos.style.color = "red";
                prezimeErrorUnos.innerHTML = "Unesite prezime!";
            }
            

            if (ok != true) {
                event.preventDefault();
                return false;
            }

            document.forms['unos'].submit();
            return true;
        }


    </script>





</body>

</html>