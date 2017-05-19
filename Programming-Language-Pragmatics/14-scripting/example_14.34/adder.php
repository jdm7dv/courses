<!DOCTYPE html>
<!-- Example 14.34 (Figure 14.14)

    To work, this file must be installed in a directory accessible to a
    web server, and the server must have PHP enabled.
-->
<html lang="en">
<head><meta charset="utf-8" />
<?php
    $argA = $_REQUEST['argA'];  $argB = $_REQUEST['argB'];
    if ($argA == "" || $argB == "") {
?>
        <title>Adder</title></head><body>
        <form action="adder.php" method="post">
        <p><input name="argA" size="3"> First addend<br />
           <input name="argB" size="3"> Second addend</p>
        <p><input type="submit"></p>
        </form></body></html>
<?php
    } else {
?>
        <title>Sum</title></head><body><p>
<?php
        $sum = $argA + $argB;
        echo "$argA plus $argB is $sum\n";
?>
        </p></body></html>
<?php
    }
?>
