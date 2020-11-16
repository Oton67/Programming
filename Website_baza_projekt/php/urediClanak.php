<?php

    include "../connect.php";

    if(isset($_POST['id'])){

        $id = $_POST['id'];
        $naslov = $_POST['naslov'];
        $kratkiSadrzaj = $_POST['kratkisadrzaj'];
        $sadrzaj = $_POST['sadrzaj'];
        $kategorija = $_POST['kategorija'];
        
        if(isset($_POST['arhivaCheck'])) $arhiva = 1;
        else $arhiva = 0;



        if(is_uploaded_file($_FILES['slika']['tmp_name'])){

            $imgDir = "img/";
            $slikaTarget = $imgDir . basename($_FILES['slika']['name']);


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
                }
            }else {
                echo "Sorry, there was an error uploading your file.";
            }

            
            $sql = "UPDATE clanak SET slika_path = ? WHERE id = ?";
            $stmt = mysqli_stmt_init($dbc);

            if(mysqli_stmt_prepare($stmt, $sql)){
                mysqli_stmt_bind_param($stmt, "si", $slikaTarget, $id);
                mysqli_stmt_execute($stmt);
            }


        }

        
        $sql = "UPDATE clanak SET naslov = ?, sazetak = ?, tekst = ?, id_kateogrija = ?, arhiva = ? WHERE id = ?";
        $stmt = mysqli_stmt_init($dbc);


        if(mysqli_stmt_prepare($stmt, $sql)){
            mysqli_stmt_bind_param($stmt, "sssiii", $naslov, $kratkiSadrzaj, $sadrzaj, $kategorija, $arhiva, $id);
            mysqli_stmt_execute($stmt);

            echo "success";


        }














    }




    header("Location: " . "../administracija.php");



?>