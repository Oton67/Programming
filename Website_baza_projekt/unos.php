<?php
    include 'connect.php';

    session_start();
    if(isset($_SESSION['username'])){

    

    $imgDir = "img/";

    $naslov = $_POST['naslov'];
    $kratkiSadrzaj = $_POST['kratkisadrzaj'];
    $sadrzaj = $_POST['sadrzaj'];
    $slikaTarget = $imgDir . basename($_FILES['slika']['name']);
    $kategorija = $_POST['kategorija'];
    
    if(isset($_POST['arhivaCheck'])) $arhiva = 1;
    else $arhiva = 0;


    $uploadOk = 1;

    if (file_exists($slikaTarget)) {
        echo "Sorry, file already exists.";
        $uploadOk = 0;
    }

    $imageFileType = strtolower(pathinfo($slikaTarget,PATHINFO_EXTENSION));

    if($imageFileType != "jpg" && $imageFileType != "png" && $imageFileType != "jpeg"
        && $imageFileType != "gif" ) {
        echo "Sorry, only JPG, JPEG, PNG & GIF files are allowed.";
        $uploadOk = 0;
    }



    if($uploadOk == 1){
        if (move_uploaded_file($_FILES["slika"]["tmp_name"], $slikaTarget)) {
            echo "The file ". basename( $_FILES["slika"]["name"]). " has been uploaded.";
        }else{
        header('Location: ' . "administracija.php?unos=no&slika=error");
        }
    }else {
        echo "Sorry, there was an error uploading your file.";
        header('Location: ' . "administracija.php?unos=no&slika=error");
    }

    $username = $_SESSION['username'];

    $sql = "SELECT id from korisnik WHERE korisnickoIme = ?";
    $stmt = mysqli_stmt_init($dbc);
    if(mysqli_stmt_prepare($stmt, $sql)){
        mysqli_stmt_bind_param($stmt, "s", $username);
        mysqli_stmt_execute($stmt);

        mysqli_stmt_store_result($stmt);
        mysqli_stmt_bind_result($stmt, $idKorisnika);
        mysqli_stmt_fetch($stmt);
    }



    // unos u bazu
    $sql = "INSERT INTO clanak (naslov, slika_path, sazetak, tekst, datumObjave, id_autora, id_kateogrija, arhiva) VALUES (?,?,?,?,?,?,?,?);";
    $stmt = mysqli_stmt_init($dbc);
    if(mysqli_stmt_prepare($stmt, $sql)){

        echo "ok";
        $datum = date("Y-m-d");
        

        mysqli_stmt_bind_param($stmt,'sssssiii', $naslov, $slikaTarget, $kratkiSadrzaj, $sadrzaj, $datum, $idKorisnika, $kategorija, $arhiva);
        mysqli_stmt_execute($stmt);

    }

    header('Location: ' . "administracija.php");
    exit;

    }

?>