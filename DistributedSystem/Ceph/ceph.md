# Ceph

pool、pg、osd 关系
各node节点的关系

```bash
ceph osd pool ls
ceph pg ls-by-pool xxx
ceph osd pool get xxx crush_rule
ceph osd crush rule create-replicated xxx default osd
ceph osd crush rule dump xxx
ceph osd pool set xxx crush_rule xxx
```
## filestash
```
docker-compose up -d
```

systemctl stop ceph
systemctl stop ceph.target 区别？

## Ceph Object Gateway
main -> rgw::AppMain::init_frontends2 -> RGWAsioFrontend::init -> AsioFrontend::init -> AsioFrontend::accept -> handle_connection -> process_request -> RGWHandler_REST::get_op -> RGWHandler_REST_Bucket_S3::op_get

## 参考
1. [https://stackoverflow.com/questions/63456581/1-pg-undersized-health-warn-in-rook-ceph-on-single-node-clusterminikube/63472905#63472905](https://stackoverflow.com/questions/63456581/1-pg-undersized-health-warn-in-rook-ceph-on-single-node-clusterminikube/63472905#63472905)

2. [filestash](https://github.com/mickael-kerjean/filestash)