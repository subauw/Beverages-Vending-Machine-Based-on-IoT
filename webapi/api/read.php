<?php
    $server = "localhost";
    $username = "root";
    $password = "";
    $dbname = "mindtrans";
    $con = mysqli_connect($server, $username, $password, $dbname) or die("unable to connect");
    $sql = "SELECT waktu FROM data_sensor LIMIT 1";
    $result = mysqli_query($con, $sql);
    $row = $result->fetch_assoc();
    echo $row["waktu"];
?>