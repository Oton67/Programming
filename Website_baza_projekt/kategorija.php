<?php
include 'connect.php';
include 'headerfooter.php';


    $idKategorija = $_GET['id'];

   






?>
<!DOCTYPE html>
<html>
<?php
    printHead("El Confidential ");


?>
<body>
    <?php
        printHeader();
    ?>
    <main class="container main">
        <div class="row">
            <div class="col">
                <a href="kategorija.php?id=<?php echo $idKategorija;?>"><h1></h1></a>
            </div>
        </div>

        <?php
            $sql = "SELECT id, naslov, slika_path, sazetak, datumObjave FROM clanak WHERE id_kateogrija = ? AND arhiva = 0;";
            $stmt = mysqli_stmt_init($dbc);
            
            if(mysqli_stmt_prepare($stmt, $sql)){
                mysqli_stmt_bind_param($stmt, "i", $idKategorija);
                mysqli_stmt_execute($stmt);
         
                
                mysqli_stmt_store_result($stmt);
                mysqli_stmt_bind_result($stmt, $id, $naslov, $slika, $sazetak, $datumObjave);
            }

            $i = 0;

            echo "<div class='row equal'>";
            while(mysqli_stmt_fetch($stmt)){
                

                echo "
                    
                <article class='col-md-4 clanak'>
                    <a href='clanak.php?id=$id'>
                        <img class='img-fluid' src='$slika'>
                    </a>
                    <p>
                        $sazetak
                    </p>
                    <span class=''>
                        | $datumObjave
                    </span>
    
                </article>
                ";

                

               
                
            }

            echo "</div>";
        ?>



        
    </main>



    <?php
        printFooter();
    ?>




</body>

</html>