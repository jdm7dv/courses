<!DOCTYPE html>
<!-- Example 14.32 (Figure 14.13)

    To work, this file must be installed in a directory accessible to a
    web server, and the server must have PHP enabled.
-->
<html lang="en">
<head><meta charset="utf-8" /><title>20 numbers</title></head>
<body>
<p>
<?php
         for ($i = 0; $i < 20; $i++) {
             if ($i % 2) { ?>
<b><?php
                 echo " $i"; ?>
</b><?php
             } else echo " $i";
         }
 ?>
</p>
</body>
</html>
