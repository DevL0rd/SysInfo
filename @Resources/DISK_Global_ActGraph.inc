; Lines starting ; (semicolons) are commented out.
; That is, they do not affect the code and are here for demonstration purposes only.
; ----------------------------------

[Rainmeter]
; This section contains general settings that can be used to change how Rainmeter behaves.
Author=Spiritreader
AppVersion=1003000
Update=1000


[Variables]
; Variables declared here can be used later on between two # characters (e.g. #MyVariable#).
fontName=Trebuchet MS
textSize=8
colorBar=235,170,0,255
colorText=255,255,255,205
driveLetter=C:

//colorBarDiskRead=141,198,63,255
colorBarDiskRead=247,148,29,255
//colorBarDiskWrite=7,234,250,255
colorBarDiskWrite=255,242,0,255
colorBarActivity=237,28,36,255

graphH=42

; ----------------------------------
; MEASURES return some kind of value
; ----------------------------------

[measureTotalDiskSpace]
Measure=FreeDiskSpace
Drive=#driveLetter#
Total=1
UpdateDivider=5

[measureUsedDiskSpace]
Measure=FreeDiskSpace
Drive=#driveLetter#
UpdateDivider=5
InvertMeasure=1

[measureDiskRead]
Measure=Plugin
Plugin=PerfMon
PerfMonObject=LogicalDisk
PerfMonCounter=Disk Read Bytes/sec
PerfMonInstance=#driveLetter#
; Gets disk read information from perfmon

[measureDiskWrite]
Measure=Plugin
Plugin=PerfMon
PerfMonObject=LogicalDisk
PerfMonCounter=Disk Write Bytes/sec
PerfMonInstance=#driveLetter#

[rawDiskIdleTime]
Measure=Plugin
Plugin=PerfMon
PerfMonObject=LogicalDisk
PerfMonCounter=% Idle Time
PerfMonInstance=#driveLetter#

[measureDiskUsageCalc]
Measure=Calc
Formula=100-rawDiskIdleTime/100000

[measureDiskIdleTime]
Measure=Calc
Formula=measureDiskUsageCalc < 0 ? 0 : measureDiskUsageCalc
DynamicVariables=1
MinValue=0
MaxValue=100

[measureDiskReadPeak]
Measure=Script
ScriptFile=#@#/FindMaxHistValue.lua
CurValue=[measureDiskRead]
HistWidth=71

[measureDiskWritePeak]
Measure=Script
ScriptFile=#@#/FindMaxHistValue.lua
CurValue=[measureDiskWrite]
HistWidth=71

; ----------------------------------
; STYLES are used to "centralize" options
; ----------------------------------

[styleTitle]
StringAlign=CENTER
StringCase=UPPER
StringEffect=SHADOW
FontEffectColor=0,0,0,40
FontColor=#colorText#
FontFace=#fontName#
FontSize=12
AntiAlias=1
ClipString=1

[styleLeftText]
StringAlign=LEFT
StringCase=NONE
StringEffect=SHADOW
FontEffectColor=0,0,0,40
FontColor=#colorText#
FontFace=#fontName#
FontSize=#textSize#
AntiAlias=1
ClipString=1

[styleRightText]
StringAlign=RIGHT
StringCase=NONE
StringEffect=SHADOW
FontEffectColor=0,0,0,40
FontColor=#colorText#
FontFace=#fontName#
FontSize=#textSize#
AntiAlias=1
ClipString=1

[styleBarDiskRead]
BarColor=#colorBarDiskRead#
BarOrientation=Vertical
SolidColor=0,0,0,40


[styleBarDiskWrite]
BarColor=#colorBarDiskWrite#
BarOrientation=Vertical
SolidColor=0,0,0,40


; ----------------------------------
; METERS display images, text, bars, etc.
; ----------------------------------

[meterHeader]
Meter=IMAGE
ImageName=#SKINSPATH#\SysInfo\img\Header.png
X=0
Y=0
H=50
W=180

[meterBody]
Meter=IMAGE
ImageName=#SKINSPATH#\SysInfo\img\Body.png
Tile=1
X=0r
Y=0R
H=149
W=180

[meterFooter]
Meter=IMAGE
ImageName=#SKINSPATH#\SysInfo\img\Footer.png
X=0
Y=0R
H=38
W=180

[meterTitle]
Meter=STRING
MeterStyle=styleTitle
X=90
Y=15
W=180
H=20
Text=#driveLetter# drive



[MeterLabelSpace]
Meter=STRING
MeterStyle=styleLeftText
X=15
Y=15R
W=145
H=14
Text="Used/Total"

[MeterSpace]
Meter=STRING
MeterStyle=styleRightText
MeasureName=measureTotalDiskSpace
MeasureName2=measureUsedDiskSpace
X=165
Y=0r
W=145
H=14
Text="%2/%1"
Percentual=0
Autoscale=1

[MeterLabelDiskRead]
Meter=STRING
MeterStyle=styleLeftText
X=15
Y=2R
W=145
H=14
Text="Read"

[MeterLabelDiskWrite]
Meter=STRING
MeterStyle=styleRightText
X=165
Y=0r
W=145
H=14
Text="Write"

[MeterRamDiskRead]
Meter=STRING
MeterStyle=styleLeftText
MeasureName=measureDiskRead
X=15
Y=2R
W=145
H=14
Text="%1B/s"
Autoscale=1
Numofdecimals=0

[MeterRamDiskWrite]
Meter=STRING
MeterStyle=styleRightText
MeasureName=measureDiskWrite
X=165
Y=0r
W=145
H=14
Text="%1B/s"
Autoscale=1
Numofdecimals=0

[MeterRamDiskReadPeak]
Meter=STRING
MeterStyle=styleLeftText
MeasureName=measureDiskReadPeak
X=15
Y=2R
W=145
H=14
Text="%1B"
Autoscale=1
Numofdecimals=0

[MeterRamDiskWritePeak]
Meter=STRING
MeterStyle=styleRightText
MeasureName=measureDiskWritePeak
X=163
Y=-14R
W=145
H=14
Text="%1B"
Autoscale=1
Numofdecimals=0


[meterHLGraphBGRead]
Meter=IMAGE
ImageName=#SKINSPATH#\SysInfo\img\GraphBGHalf.png
X=15
Y=-15R
H=#graphH#
W=72

[DiskReadGraphLine]
Meter=Line
MeasureName=measureDiskRead
LineColor=#colorBarDiskRead#
MeterStyle=styleBarDiskRead
X=1r
Y=1r
H=40
W=71
LineWidth=1
LineCount=1
AntiAlias=1
AutoScale=1

[meterHLGraphBGWrite]
Meter=IMAGE
ImageName=#SKINSPATH#\SysInfo\img\GraphBGHalf.png
X=92
Y=-41R
H=#graphH#
W=72


[DiskWriteGraphLine]
Meter=Line
MeasureName=measureDiskWrite
LineColor=#colorBarDiskWrite#
MeterStyle=styleBarDiskWrite
X=1r
Y=1r
H=40
W=71
LineWidth=1
LineCount=1
AntiAlias=1
AutoScale=1
 

[MeterLabelActivity]
Meter=STRING
MeterStyle=styleLeftText
X=15
Y=4R
W=145
H=14
Text="Activity"


[MeterDownloadPrec]
Meter=STRING
MeterStyle=styleRightText
MeasureName=measureDiskIdleTime
X=165
Y=0r
W=145
H=14
Text="%1%"
Percentual=1
Autoscale=1


[meterHLGraphBG2]
Meter=IMAGE
ImageName=#SKINSPATH#\SysInfo\img\Graphbg.png
X=15
Y=2R
H=#graphH#
W=137

[DiskIdleGraphLine]
Meter=Line
MeasureName=measureDiskIdleTime
LineColor=#colorBarActivity#
MeterStyle=styleBarDiskWrite
X=1r
Y=1r
H=40
W=135
LineWidth=1
LineCount=1
AntiAlias=1
MinValue=0
MaxValue=100

[meterHLBarCNet2BG]
Meter=IMAGE
ImageName=#SKINSPATH#\SysInfo\img\CoreBG.png
X=2R
Y=-1r
H=#graphH#
W=12

[meterBarDiskIdle]
Meter=BAR
MeterStyle=styleBarDiskWrite
MeasureName=measureDiskIdleTime
X=0r
Y=0r
Barimage=#SKINSPATH#\SysInfo\img\Core4f.png
W=12
H=#graphH#
 
 