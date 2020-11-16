<?php
    include 'connect.php';
    include 'headerfooter.php';

    if(isset($_POST['idUredjivanje'])){
        $idPost = $_POST['idUredjivanje'];
    


        $sql = "SELECT naslov, slika_path, sazetak, tekst, datumObjave, id_kateogrija, arhiva FROM clanak WHERE id = ?;";
        $stmt = mysqli_stmt_init($dbc);
        if(mysqli_stmt_prepare($stmt,$sql)){

            mysqli_stmt_bind_param($stmt, 'i', $idPost);
            mysqli_stmt_execute($stmt);
            mysqli_stmt_store_result($stmt);

        }


        mysqli_stmt_bind_result($stmt, $naslov, $slika_path, $sazetak, $tekst, $datumObjave, $id_kategorija, $arhiva);
        mysqli_stmt_fetch($stmt);
    }



  

?>
<!DOCTYPE html>
<html>


<?php
    printHead("Uredjivanje");
?>


<body>

    <main class="container main">

        <div class="row equal">
            <article class="col-md-12 clanak">
                <form id="unos" method="POST" action="php/urediClanak.php" enctype="multipart/form-data">

                    <h2>Promjena postojećeg članka!</h2>
                    <div class="form-group">
                        <label for="naslovVijesti1">Naslov vijesti</label>
                        <input type="text" class="form-control" name="naslov" id="naslovVijesti1" value="<?php echo $naslov; ?>"
                            aria-describedby="Unesite naslov vijesti!" placeholder="Unesite naslov">
                        <span id='naslovErrorUnos'></span>
                    </div>

                    <div class="form-group">
                        <label for="sadrzajTextArea">Kratki sadržaj vijesti(maksimalno 100 znakova)</label>
                        <textarea class="form-control" name="kratkisadrzaj" id="sadrzajTextArea" rows="3"
                            placeholder="Unesite kratki sadržaj"><?php echo $sazetak; ?></textarea>
                        <span id='kratkiSadrzajUnosSpan'></span>
                    </div>

                    <div class="form-group">
                        <label for="tekstTextArea">Sadržaj vijesti</label>
                        <textarea class="form-control" name="sadrzaj" id="tekstTextArea" rows="8"
                            placeholder="Unesite sadržaj"><?php echo $tekst; ?></textarea>
                        <span id='sadrzajUnosSpan'></span>

                    </div>

                    <div class="form-group">
                        <label for="slikaFile">Slika:</label>
                        <input type="file" name="slika" class="form-control-file text-center" id="slikaFile"
                            accept="image/*">
                        <span id='fileUnosSpan'></span>
                    </div>

                    <div class="form-group">
                        <label for="kategorijaSelect">Kategorija</label>
                        <select class="form-control" name="kategorija" id="kategorijaSelect">
                            <?php
                                        $sql = "SELECT * FROM kategorija";
                                        $result = mysqli_query($dbc, $sql);
                                        while($row = mysqli_fetch_array($result)){
                                            $id = $row['id'];
                                            $naziv = $row['naziv'];
                                            if($idPost == $id){
                                             echo "<option selected value='$id'>$naziv</option>";
                                            }
                                            else{
                                                echo "<option value='$id'>$naziv</option>";
                                            }
                                        }
                                    ?>
                        </select>
                    </div>


                    <div class="form-check">
                        <input class="form-check-input" type="checkbox" name="arhiva" id="arhivaCheck" <?php if($arhiva == 1) echo "selected"; ?>>
                        <label class="form-check-label"  for="arhivaCheck">
                            Spremiti u arhivu?
                        </label>
                    </div>

                    <input type="number" hidden value="<?php echo $idPost; ?>" name="id">

                    <div class="form-check">
                        <button type="reset" class="btn btn-primary ">Poništi</button>
                        <button type="button" class="btn btn-primary" id="unosPrihvati">Prihvati</button>
                    </div>
                </form>










            </article>
        </div>


    </main>


    <script>
        document.getElementById('unosPrihvati').onclick = function (event) {

            var naslov = document.getElementById('naslovVijesti1');
            var kratkiSadrzaj = document.getElementById('sadrzajTextArea');
            var sadrzaj = document.getElementById('tekstTextArea');
            var slika = document.getElementById('slikaFile');

            var ok = true;

            if (naslov.value.length < 5 || naslov.value.length > 100) {
                ok = false;
                naslov.style.border = "1px solid red";

                var naslovSpan = document.getElementById('naslovErrorUnos');
                naslovSpan.style.color = "red";
                naslovSpan.innerHTML = "Naslov mora biti između 5 i 100 znakova!";
            }

            if (kratkiSadrzaj.value.length < 10 || kratkiSadrzaj.value.length > 100) {
                ok = false;
                kratkiSadrzaj.style.border = "1px solid red";

                var kratkiSadrzajSpan = document.getElementById('kratkiSadrzajUnosSpan');
                kratkiSadrzajSpan.style.color = "red";
                kratkiSadrzajSpan.innerHTML = "Kratki sadžaj mora biti između 10 i 100 znakova!";
            }

            if (sadrzaj.value.length == 0) {
                ok = false;
                sadrzaj.style.border = "1px solid red";

                var sadrzajUnosSpan = document.getElementById('sadrzajUnosSpan');
                sadrzajUnosSpan.style.color = "red";
                sadrzajUnosSpan.innerHTML = "Sadržaj vijesti mora biti unešen!";
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