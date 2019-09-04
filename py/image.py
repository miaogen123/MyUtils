from PIL import  Image

def merge_N_same_width_images(file_list, target_name):
  #尝试合并两个图作为对比
  height_list=[]
  width=-1
  total_height=0
  img_list=[]
  if len(file_list)==0:
    return
  for file in file_list:
    img=Image.open(file)
    img_list.append(img)
    if width==-1:
      width=img.size[0]
    else:
      if width!=img.size[0]:
        raise RuntimeError("file heigths are not all same, "+file+" is diff from others")
    height_list.append(img.size[1])
    total_height+=img.size[1]
  target = Image.new('RGB', (width, total_height))
  down = 0
  up= img_list[0].size[1]
  for image in img_list:
    target.paste(image, ( 0,down, width, up))  # 将image复制到target的指定位置中
    down=up
    up+= img.size[1]
  quality_value = 100
  target.save(target_name,quality=quality_value)
#横向合并N个 images, 高要相同
def merge_N_same_height_images(file_list, target_name):
  #尝试合并两个图作为对比
  width_list=[]
  height=-1
  total_width=0
  img_list=[]
  if len(file_list)==0:
    return
  for file in file_list:
    img=Image.open(file)
    img_list.append(img)
    if height==-1:
      height=img.size[1]
    else:
      if height!=img.size[1]:
        raise RuntimeError("file heigths are not all same, "+file+" is diff from others")
    width_list.append(img.size[0])
    total_width+=img.size[0]
  target = Image.new('RGB', (total_width, height))
  left = 0
  right = img_list[0].size[0]
  count=0
  for image in img_list:
    target.paste(image, (left, 0, right, height))  # 将image复制到target的指定位置中
    left = right
    right += img.size[0]
  quality_value = 100
  target.save(target_name,quality=quality_value)

