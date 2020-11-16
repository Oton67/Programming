<?php

    $servername = "localhost";
    $username = "root";
    $password = "";
    $basename = "oton_projekt";

    $dbc = mysqli_connect($servername, $username, $password, $basename) or die("Error connecting!");
    mysqli_set_charset($dbc, "utf8");

?>