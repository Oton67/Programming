<?php

    include '../connect.php';

    if(isset($_POST['id'])){


        $id = $_POST['id'];

        $ime = $_POST['ime'];
        $prezime = $_POST['prezime'];


        if(isset($_POST['razina'])){
            $razina = 1;
        }
        else{
            $razina = 0;
        }




        $sql = "UPDATE korisnik SET ime = ?, prezime = ?, razina = ? WHERE id = ?";

        $stmt = mysqli_stmt_init($dbc);
        if(mysqli_stmt_prepare($stmt, $sql)){
            mysqli_stmt_bind_param($stmt, "ssii", $ime, $prezime, $razina, $id);
            mysqli_stmt_execute($stmt);

        }
        

    }

    mysqli_close($dbc);
    header("Location: " . "../administracija.php");
?>