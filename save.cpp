#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Create xml file\n");
        printf("Usage: %s file_name\n", argv[0]);
        exit(1);
    }
    //定义文档和节点指针
    xmlDocPtr doc = xmlNewDoc(BAD_CAST"1.0");
    xmlNodePtr root_node = xmlNewNode(NULL,BAD_CAST"Foton");

    //设置根节点
    xmlDocSetRootElement(doc,root_node);
    //在根节点中直接创建节点
    xmlNewTextChild(root_node, NULL, BAD_CAST "DeviceInfo", BAD_CAST "Foton device info!");

    //创建一个Vin节点
    xmlNodePtr nodeVin = xmlNewNode(NULL, BAD_CAST "VIN_info");
    xmlAddChild(root_node,nodeVin);
    xmlNodePtr nodeVin_len = xmlNewNode(NULL, BAD_CAST "VIN_LEN");
    xmlAddChild(nodeVin,nodeVin_len);
    xmlAddChild(nodeVin_len, xmlNewText(BAD_CAST "17"));
    xmlNodePtr nodeVin_no = xmlNewNode(NULL, BAD_CAST "VIN_NO");
    xmlAddChild(nodeVin,nodeVin_no);
    xmlAddChild(nodeVin_no, xmlNewText(BAD_CAST "0123456789abcdefg"));

    //创建一个Sn节点
    xmlNodePtr nodeSn = xmlNewNode(NULL, BAD_CAST "SN_info");
    xmlAddChild(root_node,nodeSn);
    xmlNodePtr nodeSn_len = xmlNewNode(NULL, BAD_CAST "SN_LEN");
    xmlAddChild(nodeSn,nodeSn_len);
    xmlAddChild(nodeSn_len, xmlNewText(BAD_CAST "13"));
    xmlNodePtr nodeSn_no = xmlNewNode(NULL, BAD_CAST "SN_NO");
    xmlAddChild(nodeSn,nodeSn_no);
    xmlAddChild(nodeSn_no, xmlNewText(BAD_CAST "0123456789abc"));

    //存储xml文档
    int ret = xmlSaveFormatFileEnc(argv[1], doc, "UTF-8", 1);
    if (ret != -1)
    {
       printf("create xml file, write %d bytes\n", ret);
    }
    //释放文档内节点动态申请的内存
    xmlFreeDoc(doc);
    return 0;
}
