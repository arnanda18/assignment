

<html>
    <head>
        <!-- CSS only -->
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" 
        integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">

        <link rel="stylesheet" type="text/css" href="style.css">
      <title> Calculator </title>
        
    </head>
     <?php
        $error = "";
        $x = $_POST['nilaix'];
        $y = $_POST['nilaiy'];
        $op = $_POST['opt'];
        $result = "";
            if(is_numeric($x) && is_numeric($y)){
                switch($op){
                    case '+' : $result =  $x  + $y;
                        break;
                    case '-' : $result =  $x  - $y;
                        break;
                    case 'x' : $result =  $x  * $y;
                        break;
                    case '/' : $result =  $x  / $y;
                        break;
                    
                }
            }else{
                $error = "Enter Number first";
            }
    ?>
    <body>  
        <h2>Calculator</h2>
        <div class="bd-input">
        <div class="container-sm mt-4">
            <form name="form" action="" method="POST">
                <div class="row g-4 justify-content-center">
                    <div class="col-6 col-sm-2">
                        <input type="number" class="form-control" name="nilaix" id="clearfield1" placeholder="number 1" value="<?php  echo $x; ?>">
                    </div>
                    <div class="col-6 col-sm-2">
                        <input type="number" class="form-control" name="nilaiy" id="clearfield2" placeholder="number 2" value="<?php  echo $y; ?>">
                    </div>
                    <div class="col-6 col-sm-1" style="color: white ;">
                        <h4>=</h4>
                    </div>
                    <div class="col-6 col-sm-2 result" id="clear">
                        <span>
                            <?php  echo $result; ?>
                        </span>
                    </div>  
                </div>         
                <div class="container mt-4">
                    <div class="row justify-content-left" style="margin-left: 100;">
                        <div class="col-6 col-sm-1">
                                <input  type="submit" class="btn btn-primary" name="opt" value="+"></input>
                            </div>
                            <div class="col-6 col-sm-1">
                                <input type="submit" class="btn btn-primary" name="opt" value="-"></input>
                            </div>
                            <div class="col-6 col-sm-1">
                                <input type="submit" class="btn btn-primary" name="opt" value="x"></input>
                            </div>
                            <div class="col-6 col-sm-1">
                                <input type="submit" class="btn btn-primary" name="opt" value="/"></input>
                            </div>
                            <div class="col-6 col-sm-1">
                                <input type="submit" class="btn btn-primary" onclick="ClearFields();" value="CE"></button>
                            </div>        
                    </div>
                </div>
            </form> 
        </div>
        </div>

        <script type="text/javascript">
            function ClearFields() {

                 document.getElementById("clearfield1").value = "";
                 document.getElementById("clearfield2").value = "";
            }
        </script>
    </body>
</html>
