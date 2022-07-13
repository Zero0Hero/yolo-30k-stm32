function varargout = jiemian_udp(varargin)
% JIEMIAN_UDP MATLAB code for jiemian_udp.fig
%      JIEMIAN_UDP, by itself, creates a new JIEMIAN_UDP or raises the existing
%      singleton*.
%
%      H = JIEMIAN_UDP returns the handle to a new JIEMIAN_UDP or the handle to
%      the existing singleton*.
%
%      JIEMIAN_UDP('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in JIEMIAN_UDP.M with the given input arguments.
%
%      JIEMIAN_UDP('Property','Value',...) creates a new JIEMIAN_UDP or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before jiemian_udp_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to jiemian_udp_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help jiemian_udp

% Last Modified by GUIDE v2.5 11-Jul-2022 14:44:59

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @jiemian_udp_OpeningFcn, ...
                   'gui_OutputFcn',  @jiemian_udp_OutputFcn, ...
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


% --- Executes just before jiemian_udp is made visible.
function jiemian_udp_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to jiemian_udp (see VARARGIN

hanldes.output=hObject;
handles.output = hObject;
guidata(hObject, handles);
axes(handles.axes1);
imshow(uint8(ones([72,72,3]).*255))
drawnow

% --- Outputs from this function are returned to the command line.
function varargout = jiemian_udp_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
try
    fclose(instrfindall);%先关闭之前可能存在的UDP
catch err
    
end
u1=udp(handles.addr.String,'LocalPort',eval(handles.port.String),'InputBufferSize',16384,'InputDatagramPacketSize',32768);%'RemotePort',8084,
u1.DatagramReceivedFcn = @instrcallback;%设置u1接收到数据包时，调用回调函数显示

fopen(u1);%打开udp连接
numofpacket=eval(handles.numofpacket.String);  %包个数20
bytesperpacket=eval(handles.bytesperpacket.String);   %一包的bytes 768
numflag=eval(handles.numflag.String);  %标志10个byte
IMGHW=eval(handles.IMGHW.String);
result=[];

img0=zeros(numofpacket*bytesperpacket,1);
flag=1;
global stop
stop=0;
disp('start...')
while (1)
    if (stop==1)
        break;
    end
    packindex=1;
    while packindex<=numofpacket
        result=fread(u1);
        bytesofpacket=sum(size(result))-1;
        if(bytesofpacket~=bytesperpacket) 
            continue;
        end
        
        img0((result(1))*bytesperpacket+1:(result(1)+1)*bytesperpacket)=result(1:bytesperpacket);
        img0((result(1))*bytesperpacket+(1))=img0((result(1))*bytesperpacket+IMGHW*3+1);
        packindex=packindex+1;
        if (stop==1)
            break;
        end
    end
    if (stop==0)
        for k=1:3
            t=reshape(img0(k:3:IMGHW*IMGHW*3),[IMGHW IMGHW]);
            img(:,:,k)=t';
        end
        axes(handles.axes1);
        imshow(uint8(img))
        drawnow;
    end
end
fclose(u1);%关闭udp1连接
delete(u1);%删除udp1连接，释放内存
clear u1;%清除工作区中的udp1数据
disp('done')
% --- Executes on selection change in list.
function list_Callback(hObject, eventdata, handles)
% hObject    handle to list (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns list contents as cell array
%        contents{get(hObject,'Value')} returns selected item from list
%127.0.0.1即为本地


%guidata(hObject,handles);

% --- Executes during object creation, after setting all properties.
function list_CreateFcn(hObject, eventdata, handles)
% hObject    handle to list (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes during object creation, after setting all properties.
function axes1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to axes1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: place code in OpeningFcn to populate axes1


% --- Executes during object creation, after setting all properties.
function figure1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called
ha=axes('units','normalized','pos',[0 0 1 1]);
uistack(ha,'down');
ii=imread('4.jpg');   % //////////////////////
image(ii);
colormap gray
set(ha,'handlevisibility','off','visible','on');


% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global stop
stop=1;
disp('stop...')



function addr_Callback(hObject, eventdata, handles)
% hObject    handle to addr (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of addr as text
%        str2double(get(hObject,'String')) returns contents of addr as a double


% --- Executes during object creation, after setting all properties.
function addr_CreateFcn(hObject, eventdata, handles)
% hObject    handle to addr (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function port_Callback(hObject, eventdata, handles)
% hObject    handle to port (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of port as text
%        str2double(get(hObject,'String')) returns contents of port as a double


% --- Executes during object creation, after setting all properties.
function port_CreateFcn(hObject, eventdata, handles)
% hObject    handle to port (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function numofpacket_Callback(hObject, eventdata, handles)
% hObject    handle to numofpacket (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of numofpacket as text
%        str2double(get(hObject,'String')) returns contents of numofpacket as a double


% --- Executes during object creation, after setting all properties.
function numofpacket_CreateFcn(hObject, eventdata, handles)
% hObject    handle to numofpacket (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function numflag_Callback(hObject, eventdata, handles)
% hObject    handle to numflag (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of numflag as text
%        str2double(get(hObject,'String')) returns contents of numflag as a double


% --- Executes during object creation, after setting all properties.
function numflag_CreateFcn(hObject, eventdata, handles)
% hObject    handle to numflag (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function bytesperpacket_Callback(hObject, eventdata, handles)
% hObject    handle to bytesperpacket (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of bytesperpacket as text
%        str2double(get(hObject,'String')) returns contents of bytesperpacket as a double


% --- Executes during object creation, after setting all properties.
function bytesperpacket_CreateFcn(hObject, eventdata, handles)
% hObject    handle to bytesperpacket (see GCBO)
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
