<?php
    include 'connect.php';
    include 'headerfooter.php';

?>
<!DOCTYPE html>
<html>


<?php
    printHead('Administracija');

?>


<body>
    <?php
        printHeader();
    ?>
    <main class='container main'>

    <?php
        if(isset($_SESSION['username']) == false){
            echo "<div class = 'row equal'>";
            echo "<p>Ulogirajte se kako biste mogli administrirati!";
            echo "</div>";
        }

        else{

            $username = $_SESSION['username'];
            $level = $_SESSION['level'];

            echo "<div class = 'row equal'>";
            echo "<p>Dobro došli $username, vaša razina je: "; 
            if($level == 1){
                echo "administrator!";
            }else{
                echo "korisnik";
            }

            echo "</p>";
            echo "</div>";

        
    ?>

        <?php echo "
        <div class='row equal'>

            <div class='col-md-3 razmak'>
                 <button type='button' class='btn btn-primary' onclick='prikaziUnos();'>Unos članaka</button>
            </div>
        ";
        
            
        if($_SESSION['level'] == 1){


            echo "
        
            <div class='col-md-3 razmak'>
                <button type='button' class='btn btn-primary' onclick='prikaziUredjivanje();'>Uređivanje članaka</button>
            </div>

            <div class='col-md-3 razmak'>
                <button type='button' class='btn btn-primary' onclick='prikaziBrisanje();'>Brisanje članaka</button>             
            </div>

            <div class='col-md-3 razmak'>
                <button type='button' class='btn btn-primary' onclick='prikaziUredjivanjeKorisnika();'>Uređivanje korisnika</button>
            </div>

            ";} 
            echo "
        </div> "; ?>

        
       

        <?php

            echo "
            
            <div class='row equal'>
            <article class='col-md-12 clanak'>
                <form id='unos' method='POST' action='unos.php' style='display: none;' enctype='multipart/form-data'>
                ";?>
                        <?php
                            if(isset($_GET['unos'])){
                                echo '<script> prikaziUnos();</script>';
                            }

                            if(isset($_GET['slika'])){
                                $slika = $_GET['slika'];
                                if($slika == 'error'){
                                    echo '<script> prikaziUnos();</script>';
                                    echo '<p>Greška kod učitavanja slike, slika nije slika ;)';
                                    echo '<p>Podaci nisu unešeni u bazu!</p>';
                                }
                            }
                        ?>
                        <?php echo "
                        <h2>Unos novih članaka!</h2>
                        <div class='form-group'>
                                <label for='naslovVijesti1'>Naslov vijesti</label>
                                <input type='text' class='form-control' name='naslov' id='naslovVijesti1' aria-describedby='Unesite naslov vijesti!' placeholder='Unesite naslov'>
                                <span id = 'naslovErrorUnos'></span>
                            </div>
        
                            <div class='form-group'>
                                <label for='sadrzajTextArea'>Kratki sadržaj vijesti(maksimalno 50 znakova)</label>
                                <textarea class='form-control' name='kratkisadrzaj' id='sadrzajTextArea' rows='3' placeholder='Unesite kratki sadržaj'></textarea>
                                <span id = 'kratkiSadrzajUnosSpan'></span>
                            </div>
        
                            <div class='form-group'>
                                <label for='tekstTextArea'>Sadržaj vijesti</label>
                                <textarea class='form-control' name='sadrzaj' id='tekstTextArea' rows='8' placeholder='Unesite sadržaj'></textarea>
                                <span id = 'sadrzajUnosSpan'></span>

                            </div>
        
                            <div class='form-group'>
                                <label for='slikaFile'>Slika:</label>
                                <input type='file' name='slika' class='form-control-file text-center' id='slikaFile' accept='image/*'>
                                <span id = 'fileUnosSpan'></span>
                            </div>
        
                            <div class='form-group'>
                                <label for='kategorijaSelect'>Kategorija</label>
                                <select class='form-control' name='kategorija' id='kategorijaSelect'>
                                ";?>
                                    <?php
                                        $sql = 'SELECT * FROM kategorija';
                                        $result = mysqli_query($dbc, $sql);
                                        while($row = mysqli_fetch_array($result)){
                                            $id = $row['id'];
                                            $naziv = $row['naziv'];
                                            echo "<option value='$id'>$naziv</option>";
                                        }
                                    ?>
                                    <?php echo "
                                </select>
                            </div>
        
        
                            <div class='form-check'>
                                <input class='form-check-input' type='checkbox' name='arhiva' value='' id='arhivaCheck'>
                                <label class='form-check-label' for='arhivaCheck'>
                                    Spremiti u arhivu?
                                </label>
                            </div>
                            
                            <div class='form-check'>
                                <button type='reset' class='btn btn-primary '>Poništi</button>
                                <button type='button' class='btn btn-primary ' id='unosPrihvati'>Prihvati</button>
                            </div>
                </form>

                "; ?>



                <?php

                    if($_SESSION['level'] == 1){

                    

                    echo "
                
                <!-- Promjena clanka -->
                <form id='uredjivanje' method='POST' action='uredjivanje.php' style='display: none;'>
                    <h2>Uređivanje članaka!</h2>

                    <div class='form-group razmak'>
                        <select class='form-control' name='idUredjivanje' id='promjenaClanka'>
                        ";?>
                            <?php
                                $sql = 'SELECT id, naslov, datumObjave FROM clanak ORDER BY datumObjave DESC;';
                                $stmt = mysqli_stmt_init($dbc);
                                if(mysqli_stmt_prepare($stmt,$sql)){
                                    mysqli_stmt_execute($stmt);
                                    mysqli_stmt_store_result($stmt);

                                    mysqli_stmt_bind_result($stmt, $id, $naslov, $datum);
                                    while(mysqli_stmt_fetch($stmt)){
                                        echo "<option value='$id'>$naslov $datum</option>";
                                    }
                                }
                            ?>
                        <?php echo "
                        </select>
                    </div>

                    <div class='form-group'>
                        <button type='button' class='btn btn-primary' id='gumbPromjena'>Uredi</button>
                    </div>
                  

                        
                </form>
                ";?>

                <?php echo "
                <!-- Brisanje clanaka -->
                <form id='brisanje' method='POST' action='php/brisanje.php' style='display: none;'>
                    <h2>Brisanje članaka!</h2>

                    <div class='form-group razmak'>
                        <select class='form-control' name='idBrisanje' id='brisanjeClanka'>
                        ";?>
                            <?php
                                $sql = 'SELECT id, naslov, datumObjave FROM clanak ORDER BY datumObjave DESC;';
                                $stmt = mysqli_stmt_init($dbc);
                                if(mysqli_stmt_prepare($stmt,$sql)){
                                    mysqli_stmt_execute($stmt);
                                    mysqli_stmt_store_result($stmt);

                                    mysqli_stmt_bind_result($stmt, $id, $naslov, $datum);
                                    while(mysqli_stmt_fetch($stmt)){
                                        echo "<option value='$id'>$naslov $datum</option>";
                                    }
                                }
                            ?>
                        <?php echo "
                        </select>
                    </div>

                    <div class='form-group'>
                        <button type='submit' class='btn btn-primary' id='gumbBrisanje'>Obriši</button>
                    </div>
                </form>
                ";?>


                <?php echo "
                <!-- Promjena korisnika -->
                <form id='uredjivanjeKorisnika' method='POST' action='uredjivanjeKorisnika.php' style='display: none;'>
                    <h2>Uređivanje korisnika!</h2>

                    <div class='form-group razmak'>
                        <select class='form-control' name='idKorisnik' id='uredjivanjeKorisnikaSelect'>
                        ";?>
                            <?php
                                $sql = 'SELECT id, ime, prezime, razina, korisnickoIme FROM korisnik;';
                                $stmt = mysqli_stmt_init($dbc);
                                if(mysqli_stmt_prepare($stmt,$sql)){
                                    mysqli_stmt_execute($stmt);
                                    mysqli_stmt_store_result($stmt);

                                    mysqli_stmt_bind_result($stmt, $id, $ime, $prezime, $razina, $korisnickoIme);
                                    while(mysqli_stmt_fetch($stmt)){
                                        echo "<option value='$id'>$korisnickoIme $ime $prezime Razina: $razina </option>";
                                    }
                                }
                            ?>
                        <?php echo "
                        </select>
                    </div>

                    <div class='form-group'>
                        <button type='submit' class='btn btn-primary' id='gumbKorisnik'>Uredi</button>
                    </div>  
                </form>
                






            </article>
        </div>";
        }
    }
    ?>

    </main>
    
    <script>
    <?php

    if(isset($_SESSION['username'])){
        if($_SESSION['level'] == 1){
            echo "
    
        document.getElementById('gumbKorisnik').onclick = function(event){

        var promjenaDropdown = document.getElementById('uredjivanjeKorisnikaSelect');

        var ok = true;

        if(promjenaDropdown.value == '' || promjenaDropdown == null){
            ok = false;

            promjenaDropdown.style.border = '1px solid red';
        }


        if(ok != true){
            event.preventDefault();
            return false;
        }

        document.forms['uredjivanjeKorisnika'].submit();
        return true;



        }

        document.getElementById('gumbBrisanje').onclick = function(event){

        var promjenaDropdown = document.getElementById('brisanjeClanka');

        var ok = true;

        if(promjenaDropdown.value == '' || promjenaDropdown == null){
            ok = false;

            promjenaDropdown.style.border = '1px solid red';
        }


        if(ok != true){
            event.preventDefault();
            return false;
        }

        document.forms['brisanje'].submit();
        return true;



        }

        document.getElementById('gumbPromjena').onclick = function(event){

            var promjenaDropdown = document.getElementById('promjenaClanka');

            var ok = true;

            if(promjenaDropdown.value == ''){
                ok = false;

                promjenaDropdown.style.border = '1px solid red';
            }


            if(ok != true){
                event.preventDefault();
                return false;
            }

            document.forms['uredjivanje'].submit();
            return true;



        }

        ";}}?>

        <?php

        if(isset($_SESSION['username'])){


        echo "

        document.getElementById('unosPrihvati').onclick = function(event){

            var naslov = document.getElementById('naslovVijesti1');
            var kratkiSadrzaj = document.getElementById('sadrzajTextArea');
            var sadrzaj = document.getElementById('tekstTextArea');
            var slika = document.getElementById('slikaFile');

            var ok = true;

            if(naslov.value.length < 5 || naslov.value.length > 30){
                ok = false;
                naslov.style.border = '1px solid red';

                var naslovSpan = document.getElementById('naslovErrorUnos');
                naslovSpan.style.color = 'red';
                naslovSpan.innerHTML = 'Naslov mora biti između 5 i 30 znakova!';
            }
       
            if(kratkiSadrzaj.value.length < 10 || kratkiSadrzaj.value.length > 100){
                ok = false;
                kratkiSadrzaj.style.border = '1px solid red';

                var kratkiSadrzajSpan = document.getElementById('kratkiSadrzajUnosSpan');
                kratkiSadrzajSpan.style.color = 'red';
                kratkiSadrzajSpan.innerHTML = 'Kratki sadžaj mora biti između 10 i 100 znakova!';
            }

            if(sadrzaj.value.length == 0){
                ok = false;
                sadrzaj.style.border = '1px solid red';

                var sadrzajUnosSpan = document.getElementById('sadrzajUnosSpan');
                sadrzajUnosSpan.style.color = 'red';
                sadrzajUnosSpan.innerHTML = 'Sadržaj vijesti mora biti unešen!';
            }

            if(slika.files.length == 0){
                ok = false;
                slika.style.border = '1px solid red';

                var fileUnosSpan = document.getElementById('fileUnosSpan');
                fileUnosSpan.style.color = 'red';
                fileUnosSpan.innerHTML = 'Odaberite sliku!';
            }

            if(ok != true){
                event.preventDefault();
                return false;
            }

            document.forms['unos'].submit();
            return true;
        }




    ";}?>
            
    </script>


        


<?php
    printFooter();
    mysqli_close($dbc);
?>




</body>

</html>