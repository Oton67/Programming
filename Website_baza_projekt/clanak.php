<?php
    include 'connect.php';
    include 'headerfooter.php';



    $idClanak = $_GET['id'];


    $sql = "SELECT kategorija.naziv, clanak.naslov, clanak.sazetak, clanak.slika_path, clanak.tekst, clanak.datumObjave FROM clanak INNER JOIN kategorija ON kategorija.id = clanak.id_kateogrija WHERE clanak.id = $idClanak LIMIT 0,1;";

    $stmt = mysqli_stmt_init($dbc);

    if(mysqli_stmt_prepare($stmt, $sql)){

        mysqli_stmt_execute($stmt);


        mysqli_stmt_store_result($stmt);
        mysqli_stmt_bind_result($stmt, $nazivKategorija, $naslov, $sazetak, $slika, $tekst, $datumObjave);
        mysqli_stmt_fetch($stmt);
    }   






?>
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title><?php echo $nazivKategorija; ?></title>
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
            <li class="c3"><h3><?php echo $nazivKategorija; ?></h3></li>
            </div>
        </div>
        <hr>
        <div class="row">
        <?php


        ?>
           
            <article class="col-md-12 clanak">
            <h1 class="clanak-title"><?php echo $naslov; ?></h1>
                 <p class="clanak-center">
                 <?php echo $sazetak; ?>
                </p>
                <p><img class="img-fluid" src="<?php echo $slika; ?>"></p>
                <span>
                    <p class="clanak-datum clanak-wrapper"><?php echo $datumObjave; ?></p>
                </span>
                <p class="text-justify clanak-wrapper">
                <?php
                    echo $tekst;
                ?>
                </p>
                

        </div>

    </ul>
    </main>
    
    <?php
        printFooter();
    ?>



</body>

</html>