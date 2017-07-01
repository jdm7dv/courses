<!DOCTYPE html>
<!-- Example 14.33 (Figure 14.14)

    To work, this file must be installed in a directory accessible to a
    web server, and the server must have PHP enabled.
    The companion file, add2.html, must be in the same directory.
-->
<html lang="en">
<head><meta charset="utf-8" /><title>Adder</title></head>
<body><p>
<?php
    $argA = $_REQUEST['argA']; $argB = $_REQUEST['argB'];
    $sum = $argA + $argB;
    echo "$argA plus $argB is $sum\n";
?>
</p></body></html>
