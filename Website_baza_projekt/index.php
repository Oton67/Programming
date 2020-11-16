<?php
include 'connect.php';
include 'headerfooter.php';

?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>El Confidencial</title>
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
    <ul class="ul-nomargin">
        <div class="row">
            <div class="col">
            
            <li class="c1"><a href="kategorija.php?id=1"><h3>EUROPA</h3></a></li>
            </div>
        </div>
        <div class='row equal'>
        <?php
                        
            $sql = "SELECT id, naslov, slika_path, sazetak, datumObjave FROM clanak WHERE id_kateogrija = 1 AND arhiva = 0 ORDER BY datumObjave DESC LIMIT 0,3;";
            $stmt = mysqli_stmt_init($dbc);


            if(mysqli_stmt_prepare($stmt, $sql)){
                mysqli_stmt_execute($stmt);


                mysqli_stmt_store_result($stmt);
                mysqli_stmt_bind_result($stmt, $id, $naslov, $slika, $sazetak, $datumObjave);

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
        
            }



        ?>
        </div>
        
        <hr class="hr1">

        <div class="row">
            <div class="col">
            <li class="c2"><a href="kategorija.php?id=2"><h3>TEKNAUTAS</h3></a></li>
            </div>
        </div>
        <div class="row">

        <?php
            
            $sql = "SELECT id, naslov, slika_path, sazetak, datumObjave FROM clanak WHERE id_kateogrija = 2 AND arhiva = 0 ORDER BY datumObjave DESC LIMIT 0,3;";
            $stmt = mysqli_stmt_init($dbc);


            if(mysqli_stmt_prepare($stmt, $sql)){
                mysqli_stmt_execute($stmt);


                mysqli_stmt_store_result($stmt);
                mysqli_stmt_bind_result($stmt, $id, $naslov, $slika, $sazetak, $datumObjave);

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
        
            }



        ?>
        </div>
        <hr class="hr2">
    </ul><br>
    </main>



    <?php
        printFooter();
    ?>




</body>

</html>