function varargout = com_pic(varargin)
% COM_PIC MATLAB code for com_pic.fig
%      COM_PIC, by itself, creates a new COM_PIC or raises the existing
%      singleton*.
%
%      H = COM_PIC returns the handle to a new COM_PIC or the handle to
%      the existing singleton*.
%
%      COM_PIC('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in COM_PIC.M with the given input arguments.
%
%      COM_PIC('Property','Value',...) creates a new COM_PIC or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before com_pic_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to com_pic_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help com_pic

% Last Modified by GUIDE v2.5 11-Jul-2022 10:57:54

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @com_pic_OpeningFcn, ...
                   'gui_OutputFcn',  @com_pic_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before com_pic is made visible.
function com_pic_OpeningFcn(hObject, eventdata, handles, varargin)
handles.output = hObject;
guidata(hObject, handles);
axes(handles.img);
imshow(uint8(ones([72,72,3]).*255))

function varargout = com_pic_OutputFcn(hObject, eventdata, handles) 
varargout{1} = handles.output;


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)

delete(instrfindall);
%新建串口对象
IMGHW=eval(handles.IMGHW.String);
s1=serial(handles.com.String,'BaudRate',eval(handles.baud.String)); %设置串口波特率
s1.BytesAvailableFcnMode = 'byte';%指定的字节数可用时，会发生字节可用事件
s1.InputBufferSize = IMGHW*IMGHW*3*20+15;        %输入缓冲区长度8000字节
s1.BytesAvailableFcnCount=IMGHW*IMGHW*3*2+15;   %接收8000个字节触发一次
%尝试代开串口
try
    fopen(s1);                       %打开串口对象
    global a;
    a=1;
    disp('start')
    while 1
        if(a==0)
            break
        end
        img0 = uint8(fread(s1));
        h=1;
        try
            while ~isequal(img0(h:h+14),[0;0;0;255;255;255;0;0;0;255;255;255;0;0;0;])
                if (h<IMGHW*IMGHW*3+15)
                    h=h+1;
                else
                    err('')
                end
            end
        catch err
            continue
        end
        for k=1:3
            t=reshape(img0(h+k+14:3:h+14+IMGHW*IMGHW*3),[IMGHW IMGHW]);
            img(:,:,k)=t';
        end
    
        axes(handles.img);
        imshow(img)
        disp('received!')
        drawnow
    end
    fclose(s1);  %关闭串口
    disp('Closed!')
catch err
  fclose(instrfind);               %关闭被占用的串口
  disp('Please confirm the correct serial number');   %输出错误提示
end

% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
global a
a=0;
disp('Close start')



function com_Callback(hObject, eventdata, handles)


% --- Executes during object creation, after setting all properties.
function com_CreateFcn(hObject, eventdata, handles)

if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on key press with focus on pushbutton1 and none of its controls.
function pushbutton1_KeyPressFcn(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  structure with the following fields (see MATLAB.UI.CONTROL.UICONTROL)
%	Key: name of the key that was pressed, in lower case
%	Character: character interpretation of the key(s) that was pressed
%	Modifier: name(s) of the modifier key(s) (i.e., control, shift) pressed
% handles    structure with handles and user data (see GUIDATA)



function baud_Callback(hObject, eventdata, handles)
% hObject    handle to baud (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of baud as text
%        str2double(get(hObject,'String')) returns contents of baud as a double


% --- Executes during object creation, after setting all properties.
function baud_CreateFcn(hObject, eventdata, handles)
% hObject    handle to baud (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function IMGHW_Callback(hObject, eventdata, handles)
% hObject    handle to IMGHW (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of IMGHW as text
%        str2double(get(hObject,'String')) returns contents of IMGHW as a double


% --- Executes during object creation, after setting all properties.
function IMGHW_CreateFcn(hObject, eventdata, handles)
% hObject    handle to IMGHW (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
