<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Admin Login</title>
</head>
<body>
	
	<h2>Admin Login</h2>
	
	<h4 style="color: red;">
		<?php 
		if (isset($error_message)){
			echo $error_message;
		}
		echo validation_errors();
	?>
	</h3>
	<form action="<?php echo base_url()?>index.php/login" method="POST">
		Username : <br> <input type="text" name="username" size="30"><br>
		Password : <br><input type="password" name="password" size="30"><br>
		<input type="submit" name="btnSubmit" value="Login">
	</form>
</body>
</html>
