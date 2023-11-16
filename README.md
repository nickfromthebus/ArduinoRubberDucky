# ArduinoRubberDucky
This Arduino RubberDucky script attempts to disable windows security features such as antivirus natively in windows 11. It also disables tamper protection,
and will download a payload via powershell.  Some of the timeouts may need adjusted depending on your (target's) computer speed/specs.  One unfortunate caveat
with "clicking through" the options this way is that if there are any pending notifications from Windows Security or virus/malicious file alerts is that it will
throw off the tab count and the script will malfunction.  The positive to disabling through this method is that it does not get flagged as a virusa due to the
actions being injected as keystrokes.  It will also click through any UAC prompts for disabling real time protection and tamper protection if UAC is enabled.
If UAC is not enabled, the script should still function as intended due to utilizing CTRL + Y to acknowledge UAC permission instead of {ENTER} or {SPACE} to click
the OK/Allow button.

Feel free to submit any suggestions or improvements to make this script more efficient, or function under a wider range of scenarios. I will of course give credit
It would be nice if this script was able to function as intended even with Windows Security/Virus notifications. I couldn't find any Windows 11 scripts to do this
and there were many different Windows 10 scripts that used numerous techniques to achieve very similar results, however based on my tests, clicking through the
options and allowing UAC seemed to work the best as this is the only way to truely disable tamper protection without throwing any flags or AMSI/Malware errors.

The major benefit to disabling not only real time protection but tamper protection in this way, is that once these two things are disabled, the payloads and
post exploitation possibilities are pretty much endless because known malware signatures aren't in jeaopardy of being caught at scantime or runtime. Equally 
important is the ability to run much more persistent "Disable Defender" type scripts due to tamper protection being disabled and could even be permanently disabled
or deleted with a little creativity.

This script is not perfect by any means, however it does get the job done *most* of the time. Please use this and all malicious scripts onl against targets for which
you have permission to attack, or for educational uses only. Feel free to use this script wholly, or in part, or make modifications to suit your needs, all I ask is
that the commented line stating "Original Windows 11 Disable Defender script by Nicholas Noussias" or whatever it says is maintained. you get the idea
