<!DOCTYPE html>
<!-- Example 14.31 (Figure 14.12)

    To work, this file must be installed in a directory accessible to a
    web server, and the server must have PHP enabled.
-->
<html lang="en">
<head>
<meta charset="utf-8">
<title>Status of <?php echo $host = chop(`hostname`) ?></title>
</head>
<body>
<h1><?php echo $host ?></h1>
<pre>
<?php echo `uptime`, "\n", `who` ?>
</pre>
</body>
</html>
