<?php

    include '../connect.php';

    if(isset($_POST['idBrisanje'])){
        $id = $_POST['idBrisanje'];


        $sql = "DELETE from CLANAK where id = ?";
        $stmt = mysqli_stmt_init($dbc);
        if(mysqli_stmt_prepare($stmt, $sql)){

            mysqli_stmt_bind_param($stmt, "i", $id);
            mysqli_stmt_execute($stmt);
        }

    }

    mysqli_close($dbc);
    header("Location: " . "../administracija.php");
?>