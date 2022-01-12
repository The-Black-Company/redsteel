#!/usr/bin/php
<?php
$output = "a.out";
$files = [];
$headers = [];
$debug = false;
for ($i = 1; $i < count($argv); ++$i)
{
    if ($argv[$i] == "-o")
    {
	if (isset($argv[$i += 1]))
	    $output = $argv[$i];
    }
    else if (substr($argv[$i], 0, 2) == "-I")
    {
	$headers[] = $argv[$i];
    }
    else if ($argv[$i] == "-d")
    {
	$debug = true;
    }
    else
	$files[] = $argv[$i];
}

$headers = implode(" ", $headers);

$tmpdir = sys_get_temp_dir()."/".uniqid();
foreach ($files as &$f)
{
    system("mkdir -p `dirname $tmpdir/$f`");
    system("cat $f | cpp -x assembler-with-cpp -P -nostdinc $headers > $tmpdir/$f");
    $f = $tmpdir."/".$f;
}
$files = implode(" ", $files);
if ($debug)
    system("cat $files");
system(__DIR__."/rasm $files -o $output");

